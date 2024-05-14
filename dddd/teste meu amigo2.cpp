#include <iostream>

int main(){
    
    int x,y;
    std::cout <<"digite o valor de x: ";
    std::cin >> x;
    std::cout << "\ndigite o valor de y: ";
    std::cin >> y;
    std::cout << "\n\n" << x << "," << y <<"\n\n";
    int z;
    z=y;
    y=x;
    x=z;
    std::cout << x << "," << y <<"\n\n";














    return 0;
}