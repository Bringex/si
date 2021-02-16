#include <iostream>
#include "header.h"
#include <vector>

using namespace std;


int main()
{
    // init examples
    Point point(100, 200);
    Point newPoint(point);
    newPoint.printPoint();
    newPoint = point;
    newPoint.printPoint();

    // Length
    vector<Point> points = {Point(1,2), Point(1,3), Point(1 ,4)};
    PolyLine polyLine(points);
    polyLine.printPoints();
    polyLine.getLength();

    points = {Point(3,4), Point(5,11), Point(12,8), Point(9,5), Point(5,6)};

    // Perimetr + Square
    ClosedPolyLine closedPolyLine(points);
    closedPolyLine.printPoints();
    closedPolyLine.getPerimetr();
    closedPolyLine.getSquare();



    Triangle triangle({Point(0,0), Point(2,0), Point(0,2)});
    triangle.printPoints();
    triangle.getSquare();
    triangle.getPerimetr();


    Trapeze trapeze({Point(0,0), Point(2,2), Point(4, 2), Point(4,0)});
    trapeze.printPoints();
    trapeze.getSquare();
    trapeze.getPerimetr();


    Polymorf *arr[2];
    arr[0] = new Triangle(triangle);
    arr[1] = new Trapeze(trapeze);

    for (int i = 0; i < 2; i++)
        arr[i]->printName();


    delete arr;
    // демонстрация динамического полиморфизма




    return 0;
}
