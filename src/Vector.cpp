#include "Matrix.h"
#include "math.h"

using namespace Vectors;

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z){

}

Vec3::Vec3():Vec3(0,0,0){

}

Vec3 Vec3::operator+(const Vec3& b){
    Vec3 rez;
    rez.x = x + b.x;
    rez.y = y + b.y;
    rez.z = z + b.z;
    return rez;
}

Vec3 Vec3::operator-(const Vec3& b){
    Vec3 rez;
    rez.x = x - b.x;
    rez.y = y - b.y;
    rez.z = z - b.z;
    return rez;
}

Vec3& Vec3::operator=(const Vec3& b){
    x = b.x;
    y = b.y;
    z = b.z;
    return *this;
}

Vec3& Vec3::operator+=(const Vec3& b){
    *this = *this + b;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& b){
    *this = *this - b;
    return *this;
}

Vec3 Vectors::Cross(const Vec3& a, const Vec3& b){
    Vec3 rez(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z,a.x*b.y - a.y*b.x);
    return rez;
}

Vec3& Vec3::normalize(){
    float len = sqrt(x*x+y*y+z*z);
    x = x/len;
    y = y/len;
    z = z/len;
    return *this;
}

Vec3 Vec3::operator*(const float a){
    return Vec3(x*a,y*a,z*a);
}