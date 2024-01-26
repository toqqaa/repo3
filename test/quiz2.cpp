#include <iostream>
class date
{
    int day;
    int month;
    int year;
    public:
    void setday(int d)
{
    
    day=d;
}
int getday()
{
    return day;
}
    void setmonth(int m)
{
    
    month=m;
}
int getmonth()
{
    return month;
}
 void setyear(int y)
{
    
    year=y;
}
int getyear()
{
    return year;
}
bool ValidDate(){
 if (month < 1 || month > 12)
      return false;
if (day < 1 || day > 31)
      return false;
if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return false;
return true;
}
};
int main()
{
date *date1 = new date();
int day1;
int month1;
int year1;
std::cout <<"enter a day "<<std::endl;
std::cin>>day1;
std::cout <<"enter a month "<<std::endl;

std::cin>>month1;

std::cout <<"enter a year "<<std::endl;

std::cin>>year1;
date1->setday(day1);
date1->setmonth(month1);
date1->setyear(year1);
std::cout<<date1->getday()<<"/" <<date1->getmonth()<<"/"<<date1->getyear() <<std::endl;

if (date1->ValidDate())
{
    std::cout<<" date is valid"<<std::endl;
}
else {
    std::cout<<" date  is not valid"<<std::endl;
}
return 0;


}
