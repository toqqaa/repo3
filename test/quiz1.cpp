#include<iostream>
void calculate(int n1 , int n2 , int *sum , int *product)
{
    *sum = n1+n2;
    *product = n1 *n2;

}
int main ()
{
int first;
int second;
int sum_result=0;
int product_result=0;
std::cout<<"please enter two integers \n";
std::cin>>first;
std::cin>>second;
calculate(first, second , &sum_result, &product_result);

std::cout<<"result of sum ="<<sum_result <<"\n result of product = "<<product_result<<std::endl;
return 0;

}