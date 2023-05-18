#include "shape.hpp"
#include <iostream>

#include <string>
using namespace std;

Shape::Shape(Point center, string name)
:center(center), name(name)
{
}

void Shape::print(std::ostream& out) const
{
    out << name << "(" << center.x << ", " << center.y << ")" << endl;
}


