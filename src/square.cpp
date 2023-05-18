#include "square.hpp"

using namespace std;

Square::Square(Point center, string name, int side)
:Rectangle(center, name, side, side), side(side)
{
}

Square* Square::clone() const
{
    Square* temp = new Square(*this);
    return temp;
}
