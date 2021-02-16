#include <iostream>
#include "header.h"
using namespace std;


Point::Point(float val_x, float val_y) : x(val_x), y(val_y){}
Point::Point(const Point &obj): x(obj.x), y(obj.y){//cout << "\ndefined with constructor";
}


void Point::operator=(const Point &obj) {
    x = obj.x;
    y = obj.y;
    cout << "\ndefined with operator";
}

float Point::getX() const{
    return x;
}

float Point::getY() const{
    return y;
}

void Point::printPoint(){
    cout << "\nPoint: (" << x << ", " << y << ")\n";
}

