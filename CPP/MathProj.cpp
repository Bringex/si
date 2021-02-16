#include <iostream>
#include "header.h"
#include <math.h>
using namespace std;
#include <vector>


float MathProj::getLen(Point p1, Point p2){
    return sqrt(pow(p1.getX() - p2.getX(), 2)+
                pow(p1.getY() - p2.getY(), 2));
}


float MathProj::Perimetr(std::vector<Point> vec){
    float result = 0;

    for (int i = 1; i < vec.size(); i++) {
        result += getLen(vec[i - 1], vec[i]);
    }
    result += getLen(vec[0], vec[vec.size()-1]);

    cout << "\nPerimetr: " << result;
}

float MathProj::Square(std::vector<Point> vec){
    float result = 0;

    vector<Point> newVec = vec;
    newVec.push_back(vec[0]);

    for (int i = 1; i <= newVec.size(); i++) {
        result += (newVec[i-1].getX() * newVec[i].getY()
                - newVec[i-1].getY() * newVec[i].getX());
    }

    cout.precision(2);
    cout << "\nSquare: " << abs((double) result / 2);

}

float MathProj::allLength(std::vector<Point> vec){

    float result = 0;

    for (int i = 1; i < vec.size(); i++) {
        result += getLen(vec[i - 1], vec[i]);
    }

    cout << "\nAllLength: " << result << "\n";

}



