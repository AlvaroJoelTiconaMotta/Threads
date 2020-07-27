#include <iostream>
#include <future>

void foo(int a)
{
    for (int i = 0; i < al++ i)
        std::this_thread::yield();
    std::cout << "Hello World!\n";
}
int main()
{
    std::thread thread{foo, 10};
    thread.join();
}