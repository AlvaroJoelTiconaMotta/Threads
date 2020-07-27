#include <iostream>
#include <thread>
void foo(int a)
{
    std::cout << a << '\n';
}
int main()
{
    int n;
    std::thread thread{calculateSomething, std::ref(n)};
    thread.join();
    std::cout << n << '\n';
}