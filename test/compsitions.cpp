#include <iostream>

class engine {
    public:
    engine(){

    }
  ~engine(){

}
void start(){
std::cout<<"start\n";
}
void stop (){
    std::cout<<"stop\n";
}

};
class vehicle
{
    public :
    vehicle(engine engine1): mEngine(engine1)
    {
mEngine.start();
    }

~vehicle(){
    mEngine.stop();
}
private:
engine mEngine;
};
int main(){
    engine engine1;
    vehicle car (engine1);
    return 0;
}