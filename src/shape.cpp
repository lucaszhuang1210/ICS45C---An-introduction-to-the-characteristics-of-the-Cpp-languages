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
    out << name << " at (" << center.x << ", " << center.y << ") "
         << "area = "<< this->area() << endl;
}


