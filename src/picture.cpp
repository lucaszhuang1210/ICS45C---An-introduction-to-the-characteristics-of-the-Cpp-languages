#include "picture.hpp"
#include <iostream>
#include <utility>

using namespace std;

Picture::Picture()
:head(nullptr), tail(nullptr)
{
}

Picture::Picture(const Picture& other)
:head(nullptr)
{
    head = copy(other.head);
}

Picture::Picture(Picture&& other)
:head{nullptr}, tail{nullptr}
{
    swap(other);
    other.head = other.tail = nullptr;
}

void Picture::swap(Picture& other)
{
    std::swap(head, other.head);
    std::swap(tail, other.tail);
}

Picture &Picture::operator=(const Picture& other)
{
    if (this == &other)
        return *this;
    if(head)
        free(head);
    head = copy(other.head);
    return *this;
    
}

Picture &Picture::operator=(Picture &&other)
{
    if (this == &other)
        return *this;
    free(head);
    head = other.head;
    other.head = nullptr;
    return *this;
}

void Picture::add(const Shape& shape)
{
    if (!head)
    {
        head = new ListNode{shape.clone(), nullptr};
        tail = head;
    }
    else
    {
        ListNode* temp = new ListNode{shape.clone(), nullptr};
        tail->next = temp;
        tail = temp;
    }
}

void Picture::print_all(ostream& out) const
{
    for (ListNode* p = head; p!=nullptr; p = p->next)
        p->shape->print(out);
}

void Picture::draw_all(ostream& out) const
{
    for (ListNode* p = head; p!=nullptr; p = p->next)
        p->shape->draw(out);
}

double Picture::total_area() const
{
    double total = 0.00;
    for (ListNode* p=head; p!=nullptr; p=p->next)
        total += p->shape->area();
    return total;
}

Picture::~Picture()
{
    free(head);
}

Picture::ListNode* Picture::copy(ListNode* head)
{
    if(!head)
        return nullptr;
    return new ListNode{head->shape->clone(), copy(head->next)};
}

