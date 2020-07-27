#include <iostream>
#include <thread>
class Bar
{
public:
    void foo(int a)
    {
        std::cout << a << '\n';
    }
};
int main()
{
    Bar bar;
    std::thread thread(&Bar::foo, &bar, 10);
    thread.join();
    return 0;
}
