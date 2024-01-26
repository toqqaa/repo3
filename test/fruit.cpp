#include<iostream>

struct Fruit {
    double weight;
    double pricePerKg;
    double total;
};

int main() {
    Fruit fruit;

    
    std::cout << "Enter the weight of  fruit is : ";
    std::cin >> fruit.weight;

    
    std::cout << "Enter the price per kilogram of fruit is : ";
    std::cin >> fruit.pricePerKg;

   
    fruit.total = fruit.weight * fruit.pricePerKg;

    std::cout << "The total cost of  fruit is:" << fruit.total << std::endl;

    return 0;
}
