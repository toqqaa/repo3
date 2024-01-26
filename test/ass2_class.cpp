#include<iostream>
class person
{
    public:
void setname(const std::string &n1)
{
    name=n1;
}
std::string getname()
{
    return name;
}
void setage(int age1)
{
    
    age=age1;
}
int getage()
{
    return age;
}
void setcountry(const std::string &c1)
{
    country=c1;
}
std::string  getcountry()
{
    return country;
}
void display(){
    std::cout<<" name is : " <<getname()<< "\n age is: "<<getage()<<"\n country is : "<<getcountry()<<std::endl;


}




private:
std::string  name ;
int age ;
std::string country;

};
int main()
{
    person *person1 = new person();
    person1->setage(21);
    person1->setname("toka");
    person1->setcountry("egypt");
    person1->display();
    return 0;

}