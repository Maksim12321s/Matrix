#include <iostream>
#include "Matrix.h"
#include <vector>

int main(){

    Matrix a(2,2);
    Matrix b(2,1);
    std::vector<float> aData = {1.0f,2.0f,3.0f,4.0f};
    std::vector<float> bData = {5.0f,6.0f};
    
    a(aData);
    b(bData);
    a.Show();
    std::cout << "-------------------" << std::endl;
    b.Show();
    std::cout << "-------------------" << std::endl;
    Matrix c(1,1);
    
    c = a*b;
    c.Show();
    std::cout << "Helo" << std::endl;
    return 0;

}