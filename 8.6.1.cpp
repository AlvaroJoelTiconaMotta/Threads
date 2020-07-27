#include <future>
#include <iostream>

class thread_joiner
{
public:
    thread_joiner(std::thread t)
        : t_(std::move(t))
    {
    }
    ~thread_joiner()
    {
        if (t_.joinable())
        {
            t_.join();
        }
    }

private:
    std::thread t_;
};

void perform_work()
{
    // Perform some work
}
void t()
{
    thread_joiner j{std::thread(perform_work)};
}