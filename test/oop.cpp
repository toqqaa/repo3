#include <iostream>


struct Employee
{
   int id; 
   int salary;
   std::string name;
   bool hire_status;

   Employee()
   {
    std::cout << "constructor is called" << std::endl;
   }

   void Hire()
   {
    hire_status = true;

   }

   void fire()
   {
    hire_status = false;
   }

   void display()
   {
    std::cout << "id = " << id << "\nname = " << name << "\nsalary = "<< salary << "\nHired" << hire_status << std::endl;
   }


};

Employee emp1;

int main(int argc, char const *argv[])
{
    emp1.id = 1;
    emp1.name = "tarek";
    emp1.salary = 1000;
    emp1.Hire();
    emp1.display();
    
    return 0;
}

