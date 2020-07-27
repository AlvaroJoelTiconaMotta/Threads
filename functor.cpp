#include <iostream>
#include <thread>
class Bar
{
public:
    void operator()(int a)
    {
        std::cout << a << '\n';
    }
};
int main()
{
    Bar bar;
    std::thread thread(bar, 10);
    thread.join();
    return 0;
}
