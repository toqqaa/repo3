#include <iostream>

void input(int matrix[][2])
{

 for (int row = 0; row < 2; row++)
        {
            for (int column = 0; column < 2; column++)
            {
                std::cin >> matrix[row][column];
            }

         }
 }


void display(int matrix[][2])
{

 for (int row = 0; row < 2; row++)
        {
            for (int column = 0; column < 2; column++)
            {
                 std::cout << "matrix [" << row << "][" << column << "]=" << matrix[row
                ][column] <<std::endl;
            }

        }

}


  int main(int argc, const char** argv) 

{
    int matrix[2][2] = {
                        {2,8},
                        {10,17}
                        };
        std::cout << "please enter matrix values" << std::endl;
        input(matrix);
        display(matrix);

    return 0;
}
