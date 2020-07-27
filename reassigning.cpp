#include <thread>
void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
}
int main()
{
    std::thread executors[100];
    for (int i = 0; i < 100; i++)
    {
        if (!executors[i].joinable())
            executors[i] = std::thread(foo);
    }
}