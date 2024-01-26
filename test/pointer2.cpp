#include <iostream>

int main(int argc, char const *argv[])
{
    double balance[5] = {100.7, 1000, 500, 800, 970};

    double *d_ptr = balance;

    for (int i = 0; i < 5; i++)
    {
       //std::cout << *(balance +1) << std::endl;
       std::cout << d_ptr[i] << std::endl;
    }
    
    std::cout << balance+0 << std::endl;
     std::cout << balance+1 << std::endl;
 

    return 0;
}
