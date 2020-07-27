#include <iostream>
#include <thread>

void foo(int &b)
{
    b = 10;
}

int main()
{
    int a = 1;
    std::thread thread{foo, std::ref(a)};
    thread.join();
    std::cout << a << '\n';
}
