#include <iostream>
#include <future>

void foo()
{
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::hours(3));
}
int main()
{
    std::thread thread{foo};
    thread.join();
    std::cout << "We are now located 3 hours after the thread has been called\n";
}
