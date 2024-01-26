#include <iostream>


class person 
{
private:
std::string name;
int age; 
std::string country;

public:

void setName(const std::string & n)
{
    name = n;
}
void setAge(int a)
{
    age = a;

}

void setCountry(const std::string & c)
{
    country = c;
}

std::string getName()
{
    return name;
}

int getAge()
{
    return age;
}

std::string getCountry()
{
    return country;
}

void display()
{
    std::cout << "name is:" << name
    <<"\nAge is:" << age
    << "\nCountry is:" << country;

}

};

person p;

int main(int argc, char const *argv[])
{
  p.setName("farah");
  p.setAge(22);
  p.setCountry("Egypt");
  p.display();


  return 0;


}



