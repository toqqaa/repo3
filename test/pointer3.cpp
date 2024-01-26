#include <iostream>


int add(int x, int y)
{
    return x+y;
}



int main(int argc, char const *argv[])
{
    int (*f_ptr)(int, int) = add;
    std::cout << "result =" << f_ptr(3,5)  << std::endl;
    return 0;
}
