#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include <string>

// class Shape
struct Point {
    int x;
    int y;
};

class Shape {
public:
    // construct this Shape with given center and name
    Shape(Point center, std::string name);

    // print in format: name(center.x, center.y) e.g., Circle_2(1.0, 2.3)
    void print(std::ostream& out) const;

    Shape& operator=(const Shape& other) = delete;

    virtual double area() const = 0;

    virtual void draw(std::ostream& out) const = 0;

    virtual Shape* clone() const = 0;

    virtual ~Shape() = default;

protected:
    Shape(const Shape& other) = default;

private:
    Point center;

    std::string name;
};

#endif



