#include "triangle.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

Triangle::Triangle(Point center, string name, int base, int height)
:Shape(center, name), base(base), height(height)
{
}

double Triangle::area() const
{
    return 1.00/2.00 * base * height;
}

void Triangle::draw(ostream& out) const
{
    int offset = std::max(height, base);
    for (int i = 0; i < height; i += 2) {
        for (int j = 0; j < (offset - i) / 2; ++j) {
            out << ' ';
        }
        for (int k = 0; k <= i; ++k) {
            out << '*';
        }
        out << '\n';
    }
}

Triangle* Triangle::clone() const
{
    Triangle* temp = new Triangle(*this);
    return temp;
}
