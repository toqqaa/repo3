#include <iostream>
#include <array>
//abstract class
class shape 
{

    public:
   virtual void show () =0;// pure virtual function
   
};
class circle : public shape{
    public:
     void show() override
    {
        std::cout<<"show circle\n";
    }
};
class triangle : public shape 
{
    public :
    void show()override
    {
std::cout<<"show triangle\n";
    }
};
void makePicture (std::array<shape* ,2 > list)
{
    for (auto shape : list)
    {
        shape->show();
    }
}

int main()
{
    circle c;
    triangle t;


 shape *sptr = &c;
   sptr->show();
  std::array<shape* ,2 >shapes;
  shapes [0]=sptr;
  shapes [1]=&t;

makePicture(shapes) ;
    return 0;
}