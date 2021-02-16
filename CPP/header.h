#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>


class Polymorf{
public:
    virtual void printName() = 0;
};


class Point{
private:
    float x;
    float y;
public:
    Point(float, float);
    Point(const Point &obj); //copy
    void operator=(const Point &obj); // =
    float getX() const;
    float getY() const;
    void printPoint();
};

class MathProj{
private:
    float getLen(Point, Point);
public:
    float Perimetr(std::vector<Point>);
    float Square(std::vector<Point>);
    float allLength(std::vector<Point>);

};

class PolyLine : public MathProj, public Polymorf{
public:
    std::vector<Point> vec;
    PolyLine(std::vector<Point>);
    PolyLine(const PolyLine &obj);
    ~PolyLine();
    void getLength();
    void printPoints();
    void printName();
};

class ClosedPolyLine : public PolyLine{
public:
    ClosedPolyLine(std::vector<Point>);
    ClosedPolyLine(const ClosedPolyLine &obj);
    ~ClosedPolyLine();
    void getPerimetr();
    void getSquare();
    void printPoints();
};

class Triangle : public ClosedPolyLine {

public:
    Triangle();
    Triangle(std::vector<Point>);
    Triangle(const Triangle &obj);
    ~Triangle();

    void getPerimetr();
    void getSquare();
    void printName();
    void printPoints();

};

class Trapeze : public ClosedPolyLine{
public:
    Trapeze(std::vector<Point>);
    Trapeze(const Trapeze &obj);
    ~Trapeze();
    void getPerimetr();
    void getSquare();

    void printName();
    void printPoints();

};


#endif // HEADER_H_INCLUDED
