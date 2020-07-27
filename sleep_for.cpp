#include <iostream>
#include <future>

void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
}
int main()
{
    std::thread thread{foo};
    foo.join();
    std::cout << "Waited for 3 seconds!\n";
}
