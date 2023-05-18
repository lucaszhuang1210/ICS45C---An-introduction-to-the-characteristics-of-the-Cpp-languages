#include "rectangle.hpp"
#include <iostream>

using namespace std;

Rectangle::Rectangle(Point center, string name, int width, int height)
:Shape(center, name), width(width), height(height)
{
}

double Rectangle::area() const
{
    return 1.00 * width * height;
}

void Rectangle::draw(ostream& out) const
{
    for (int i = 0; i < height; i += 2) {
        for (int j = 0; j < width; ++j) {
            out << '*';
        }
        out << '\n';
    }
}

Rectangle* Rectangle::clone() const
{
    Rectangle* temp = new Rectangle(*this);
    return temp;
}
