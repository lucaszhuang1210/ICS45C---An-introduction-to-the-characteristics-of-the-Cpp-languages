#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

// class Rectangle
class Rectangle : public Shape
{
public:
    Rectangle(Point center, std::string name, int width, int height);

    double area() const override;
    void draw(std::ostream& out) const override;
    Rectangle* clone() const override;

protected:
    Rectangle(const Rectangle& other) = default;

private:
    int width;
    int height;
};

#endif
