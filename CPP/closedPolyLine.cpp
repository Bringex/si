#include <iostream>
#include "header.h"
#include <vector>
using namespace std;


ClosedPolyLine::ClosedPolyLine(vector<Point> newVec) : PolyLine(newVec){}

ClosedPolyLine::ClosedPolyLine(const ClosedPolyLine &obj) : PolyLine(obj.vec){}
ClosedPolyLine::~ClosedPolyLine(){};

void ClosedPolyLine::printPoints(){
    cout << "Closed PolyLine: ";
    for (int i = 0; i < ClosedPolyLine::vec.size(); i++) {
        cout << "(" << vec[i].getX()
                  << ", " << vec[i].getY() << ") ";
    }

}

void ClosedPolyLine::getPerimetr(){
    Perimetr(vec);
}

void ClosedPolyLine::getSquare(){
    ClosedPolyLine::Square(vec);
}
