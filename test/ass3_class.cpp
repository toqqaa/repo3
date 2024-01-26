#include <iostream>
class shape
{
    public:
    int width_t=4;
    int height_t=16 ;
    int width_r=10; 
    int height_r=20 ;
    
shape(){


std::cout<<" constructor is called"<<std::endl;
}

};
class triangle : public shape
{public:
int area(){
    return 0.5*width_t*height_t;
}

};
class rectangle : public shape
{public:
int area(){
    return width_r*height_r;
}
};
int main()
{
triangle triangle;
rectangle rect;
triangle.area();
rect.area();
std::cout<<" Area of triangle = "<<triangle.area()<<"\n Area of rectangle = "<<rect.area()<<std::endl;
}