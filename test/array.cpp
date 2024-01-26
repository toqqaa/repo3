#include <iostream>

int main(int argc, char const *argv[])
{
    int price_orange_week1 [7] = {10,15,15,18,20};
    for (int i = 0; i < 7; i++)
    {
        std::cin >> price_orange_week1[i];
    }
    



    
    for(int i = 0; i < 7; i++)
    {
        std::cout << "price_orange_week1[" << i << "] = " << price_orange_week1[i] << std::endl;
    }

    char word[5] = {'h','e', 'l', 'l', 'o'};
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if (word[i] == word[j])

            {
                word[i] = 'M';

            }
            
        }
   
        std::cout << word[i] << std::endl;
    }
    return 0;
}
