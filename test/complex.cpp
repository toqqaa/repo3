#include <iostream>
class complex

{float  real;
float  img;
public:
    complex (float r , float i)
    {
     real =r;
      img =i;
    }
    complex( const complex & obj)
    {
        this->real=obj.real;
        this->img=obj.img;
    }
complex operator+ (complex const obj)
{
    complex result (0,0);
    result.real =real+ obj.real;
    result.img = img+ obj.img;
    return result;


}
complex & operator =(complex obj)
{
 this->real=obj.real;
  this->img=obj.img;
  return *this;
}
friend std::ostream& operator <<(std::ostream& out , complex obj);// allow the private member to be allowed in ostream

};
std::ostream& operator <<(std::ostream& out , complex obj)
{
    out<<obj.real<< " +i"<<obj.img<<std::endl;
    return out;


}

int main ()
{

    complex c1 (10.0,20.0);
    complex c2 (20.0,30.0);
   // complex Complex1(c1);
    complex c3 = c1 +c2;
    std::cout<<c3;

  
    return 0;
}