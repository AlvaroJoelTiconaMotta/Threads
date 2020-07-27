#include <future>
#include <iostream>
struct tasks
{
    std::mutex m;
    std::condition_variable v;
    std::deque<std::packaged_task<void()>> work;
    std::vector<std::future<void>> finished;
    template <class F, class R = std::result_of_t<F &()>>
    std::future<R> queue(F &&f)
    {
        std::packaged_task<R()> p(std::forward<F>(f));
        auto r = p.get_future();
        {
            std::unique_lock<std::mutex> l(m);
            work.emplace_back(std::move(p));
        }
        v.notify_one();
        return r;
        void start(std::size_t N = 1)
        {
            for (std::size_t i = 0; i < N; ++i)
            {

                finished.push_back(
                    std::async(
                        std::launch::async,
                        [this] { thread_task(); }));
            }
        }
        void abort()
        {
            cancel_pending();
            finish();
        }
        void cancel_pending()
        {
            std::unique_lock<std::mutex> l(m);
            work.clear();
        }
        void finish()
        {
            {
                std::unique_lock<std::mutex> l(m);
                for (auto &&unused : finished)
                {
                    work.push_back({});
                }
            }
            v.notify_all();
            finished.clear();
        }
        ~tasks()
        {
            finish();
        }

    private:
        void thread_task()
        {
            while (true)
            {
                std::packaged_task<void()> f;
                {
                    std::unique_lock<std::mutex> l(m);
                    if (work.empty())
                    {
                        v.wait(l, [&] { return !work.empty(); });
                    }
                    f = std::move(work.front());
                    work.pop_front();
                }
                if (!f.valid())
                    return;
                f();
            }
        }
    }
};