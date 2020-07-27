#include <future>
#include <iostream>
unsigned int square(unsigned int i)
{
    return i * i;
}
int main()
{
    auto f = std::async(std::launch::async, square, 8);
    std::cout << "square currently running\n";
    std::cout << "result is " << f.get() << '\n';
}
