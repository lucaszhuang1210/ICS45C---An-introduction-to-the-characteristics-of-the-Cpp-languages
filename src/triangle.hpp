#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

// class Triangle
class Triangle : public Shape
{
public: 
    Triangle(Point center, std::string name, int base, int height);

    double area() const override;
    void draw(std::ostream& out) const override;
    Triangle* clone() const override;

protected:
    Triangle(const Triangle& other) = default;

private:
    int base;
    int height;
};

#endif
