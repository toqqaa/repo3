#include<iostream>

struct StudentRecord
{
    int id;
    std::string name;
    int age;
    double gpa;


};
int main()
{
StudentRecord *record_list= new StudentRecord [12];
for (int i=0; i<3; i++){


        std::cin>>record_list[i].id;
        std::cin>>record_list[i].name;
        std::cin>>record_list[i].age;
        std::cin>>record_list[i].gpa;
}


for (int i=0; i<3; i++){


std::cout<<"student id ["<<i<<"] = "<<record_list[i].id<<std::endl;
std::cout<<"student name ["<<i<<"] = "<<record_list[i].name<<std::endl;

std::cout<<"student age ["<<i<<"] = "<<record_list[i].age<<std::endl;
std::cout<<"student gpa ["<<i<<"] = "<<record_list[i].gpa<<std::endl;
}


delete [] record_list;

    return 0;

}

