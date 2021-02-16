#include <iostream>
#include "header.h"
#include <vector>
using namespace std;

Trapeze::Trapeze(vector<Point> newVec) : ClosedPolyLine(newVec){}

Trapeze::Trapeze(const Trapeze &obj) : ClosedPolyLine(obj.vec){}

Trapeze::~Trapeze(){ cout << "\nTrapeze killed"; };

void Trapeze::printPoints(){
    cout << "\nTrapeze: ";
    for (int i = 0; i < Trapeze::vec.size(); i++) {
        cout << "(" << vec[i].getX()
                  << ", " << vec[i].getY() << ") ";
    }

}

void Trapeze::printName(){
    cout << "\nTrapeze polymorf";
}

void Trapeze::getPerimetr(){
    Trapeze::Perimetr(vec);
}

void Trapeze::getSquare(){
    Trapeze::Square(vec);
}
