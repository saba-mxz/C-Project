#include <iostream>
int main()
{
    int x = 10;
    int* ptr;
    ptr = new int;
    *ptr = x;
    std::cout << *ptr;
    delete ptr;
}
