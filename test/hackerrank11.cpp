#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct person
{
    int age;
    std::string  first_name;
    std::string  second_name;
    int standard;
    
};
int main() {
    person person;
    std::cin>>person.age;
    std::cin>>person.first_name;
    std::cin>>person.second_name;
    std::cin>>person.standard;
    std::cout<<person.age<<" "<<person.first_name<<" "<<person.second_name<<" "<<person.standard<<std::endl;
    return 0;
}
