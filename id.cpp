#include <iostream>
#include <future>
void foo()
{
    std::cout << std::this_thread::get_id() << '\n';
}

int main()
{
    std::thread thread{foo};
    thread.join();
    foo();
}
