#include <iostream>
#include "header.h"
#include <vector>
using namespace std;

Triangle::Triangle(vector<Point> newVec) : ClosedPolyLine(newVec) {}

Triangle::Triangle(const Triangle &obj) : ClosedPolyLine(obj.vec) {}

Triangle::~Triangle(){ cout << "\nTriangle killed"; };


void Triangle::printPoints(){
    cout << "\nTriangle: ";
    for (int i = 0; i < Triangle::vec.size(); i++) {
        cout << "(" << vec[i].getX()
                  << ", " << vec[i].getY() << ") ";
    }

}

void Triangle::printName(){
    cout << "\nTriangle polymorf";
}

void Triangle::getPerimetr(){
    Triangle::Perimetr(vec);
}

void Triangle::getSquare(){
    Triangle::Square(vec);
}
