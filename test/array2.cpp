#include <iostream>


int main(int argc, char const *argv[])
{
  char word[6] = {'h','e', ' ', 'l', 'o', ' '};
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; i < 5; j++)
    {
        if (word[i]*word[j] == 0)
        {
             std::cout << word[j] << std::endl;
        }
        
    }
    
  }
  


    return 0;
}






