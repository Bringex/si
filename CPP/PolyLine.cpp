#include <iostream>
#include "header.h"
#include <vector>
using namespace std;

PolyLine::PolyLine(vector<Point> new_vec) : vec(new_vec) {}
PolyLine::PolyLine(const PolyLine &obj){
    vec = obj.vec;
}
PolyLine::~PolyLine(){}

void PolyLine::printName(){

}
void PolyLine::printPoints(){
    cout << "PolyLine: ";
    for (int i = 0; i < PolyLine::vec.size(); i++) {
        cout << "(" << vec[i].getX()
                  << ", " << vec[i].getY() << ") ";
    }
    cout << "\n";
}

void PolyLine::getLength(){
    PolyLine::allLength(vec);
}


