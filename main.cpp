#include <iostream>
#include "Matrix.h"
#include <vector>
using namespace Vectors;
int main(){

    
    float *arr = new float[4];
    arr[0] = 0.1;
    arr[1] = 0.2;
    arr[2] = 0.3;
    arr[3] = 0.4;
    Matrix a(2,2,arr);
    Matrix b(a);
    a.show();
    b.show();
    Matrix c(2,2);
    c = b + a;
    c.show();
    c -= a;
    c.show();
    c -= a;
    c.show();
    Vec3 newVec(1,2,3);
    return 0;

}