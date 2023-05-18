#ifndef PICTURE_HPP
#define PICTURE_HPP

#include <iosfwd>
#include "shape.hpp"

// class Picture
class Picture
{
public: 
    Picture();

    Picture(const Picture& other);
    Picture(Picture&& other);

    void swap(Picture& other);

    Picture & operator=(const Picture& other);
    Picture & operator=(Picture&& other);

    void add(const Shape& shape);

    void print_all(std::ostream& out) const;
    void draw_all(std::ostream& out) const;

    double total_area() const;

    ~Picture();

private:
    struct ListNode 
    {
        Shape* shape;
        ListNode* next;
    };

    ListNode* head;
    ListNode* tail;
};

#endif
