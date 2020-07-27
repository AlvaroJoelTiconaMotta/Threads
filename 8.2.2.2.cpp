#include <iostream>
#include <thread>
class ComplexObject
{
public:
    void doCalculations();
    void getResult();
};
void bar(const ComplexObject &co)
{
    co.doCalculations();
}
int main()
{
    ComplexObject object;
    std::thread thread{bar, std::cref(object)};
    thread.join();
    std::cout << object.getResult() << '\n';
}
