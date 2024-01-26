#include<iostream>
class animal {
    public:
    std::string name;
    int age;
void set_value(const std::string n, int a){
    name = n;
    age =a;


}
};
class zebra  : public animal
{
    public:

void displayZebra(){
    std::string color1="black&white";
    std::cout<<"zebra name is : "<<name<<"\n zebra age is : "<<age<< "\nzebra color is :"<< color1 <<std::endl;


};



};
class dolphine : public animal
{
    public:
    void displayDolphine(){
        
std::string color2="black";
std::cout<<"dolphine name is : "<< name <<"\n dolphine age is : "<<age<< "\ndolphine color is :"<< color2 <<std::endl;
    }
};
int main()
{
zebra zebr;
dolphine dolph;
zebr.set_value("mark" ,5);
dolph.set_value("ash" , 3);
zebr.displayZebra();
dolph.displayDolphine();
return 0;




}
