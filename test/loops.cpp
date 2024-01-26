#include <iostream>


int readSensor()
{
    return 105;
}

int main(int argc, char const *argv[])
{
    int sensor_data[5];
    for (int i = 0; i < 5; i++)
    {
        sensor_data[i] = readSensor();
        std::cout << "sensor_data[" << i << "] = " << sensor_data[i] << std::endl;
        
    }

    //loops --> repetition
    for (int counter  = 0; counter < 10; counter++)
    {
        if (sensor_data[counter] == 105)
        {
            std::cout << "threshold value detected\n" << std::endl;
        }
        
    }
    
    return 0;
}
