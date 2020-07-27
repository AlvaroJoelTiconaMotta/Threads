#include <iostream>
#include <thread>
int main()
{
    auto lambda = [](int a) { std::cout << a << '\n'; };
    std::thread thread(lambda, 10);
    thread.join();
    return 0;
}