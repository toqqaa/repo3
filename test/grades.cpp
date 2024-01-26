#include <iostream>

int add(int first_num, int second_num)
{
    return first_num + second_num;

}
void welcome();


int main(int argc, char const *argv[])
{

    unsigned int grade= 0;
    std::cout << "enter your grade \n" << std::endl;
    std::cin >> grade;
    if (grade < 50)
    {
std::cout << "failed" << std::endl;    }
    
    else if (grade >= 50 && grade <=65)
    {
        std::cout << "pass \n" << std::endl;
    }

    else if (grade >= 65 && grade <= 75)
    {
        std::cout << "good \n" << std::endl;
    }

    else if (grade >= 75 && grade <= 85)
    {
        std::cout << "very good \n" << std::endl;
    }

    else
     {
     std::cout << "excellent \n" << std::endl;
    }

    return 0;
}
