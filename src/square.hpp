#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "rectangle.hpp"

// class Square
class Square : public Rectangle
{
public:
    Square(Point center, std::string name, int side);

    Square* clone() const override;

protected:
    Square(const Square& other) = default;

private: 
    int side;
};

#endif

