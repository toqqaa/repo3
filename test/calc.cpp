#include <iostream>


double add(double n1 , double n2)
{
    return n1 + n2; 
}

double sub(double n1 , double n2)
{ 
    return n1 - n2;
}

double mul(double n1 , double n2)
{ 
    return n1 * n2;
}

double div(double n1 , double n2)
{ 
    return n1 / n2;
}

int main(int argc, char const *argv[])
{
    char op;
    int first =0;
    int second=0;
 std::cout << "enter first number" << std::endl;
 std::cin >> first;
 std::cout << "enter second number" << std::endl;
 std::cin >> second;

 std::cout << "enter desired operator ( + - * / )" << std::endl;
 std::cin >> op;
 int result = 0;
if (op == '+')
{
result = add(first, second);

}    

if (op == '-')
{
result = sub(first, second);

} 

if (op == '*')
{
result = mul(first, second);

} 

if (op == '/')
{
result = div((double)first, (double)second);

} 


std::cout << "result =" << result << std::endl;
    return 0;
}
