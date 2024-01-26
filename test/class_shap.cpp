#include <iostream>


class Shape
 {
 public:

  void setWdith(int local_width) 
 {    
   width = local_width;
 }
 int getWidth()  
{
  return width; 
}
void setHeight(int height)   
 {
   this->height = height;
  }   
  
   int getHeight()  
{     
   return this->height;
 }
 int area()  
 {   
 return width * height;   
  }  
private:  
int width;    
int height;
};

class Rectangle : public Shape

{
public:  
  Rectangle() 
     {

     } 
     void display()    
     {
      std::cout << "width " << getWidth()   
           << " height " << getHeight()  
          << " area " << area() << "\n";  
            }
        };
        
    int main()
    {
    Rectangle rect; 
    rect.setWdith(5);
    rect.setHeight(10);
    rect.display(); 
     
  return 0;}