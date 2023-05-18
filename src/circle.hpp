#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

// class Circle 
class Circle : public Shape
{
public: 
    Circle(Point center, std::string name, int radius);

    double area() const override;
    void draw(std::ostream& out) const override;
    Circle* clone() const override;

protected:
    Circle(const Circle& other) = default;

private:
    int radius;
};

#endif
