#include <iostream>
class circle{
    public:

void setradius(int radius1)
{
    radius=radius1;
}
int getradius()
{
    return radius;
}


float circum(){
    return 2*3.14*radius;;
}

  float area()
    {
        return 3.14*(radius*radius);
    }
void display(){
    

    std::cout<<"Area = " << area()<<"\nthe circumference = "<<circum()<<std::endl;
  
}


    private:
    int radius;
};

int main()
{
    circle *circle1 = new circle();

    circle1->setradius(5);
    circle1->display();
    circle1->area();
    circle1->circum();
    

}