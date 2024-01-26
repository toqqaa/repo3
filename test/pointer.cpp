#include <iostream>

void modifyTo100(int *ptr)
{
    *ptr = 100;
}
int main(int argc, char const *argv[])
{
    int *p = nullptr;
    int x=10;
    int y = 800;
    p = &y;
    *p += 200;
    std::cout << "*p = " << *p << std::endl;

    p = &x;
    *p=7;

    std::cout << "adress of pointer = " << &p << 
    "\n pointer p value = " << p 
    << "\n adress of variable = " << &x << std::endl;
    
    modifyTo100(p);

std::cout << *p << std::endl;



    return 0;
}
