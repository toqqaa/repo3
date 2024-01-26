#include <iostream>

int main()
{
    char* str = "good morning";
        std::cout << "size of pointer " << sizeof(char*)   << std::endl;
        std::cout << "size of pointer " << sizeof(int*)   << std::endl;
        std::cout << "size of pointer " << sizeof(double*)   << std::endl;

    for (int i = 0; i < 13; i++)

    {
       
    std::cout << *(str+i) << std::endl;

    }
    


    return 0;
}
