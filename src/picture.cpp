#include "picture.hpp"
#include <iostream>
#include <utility>

using namespace std;

Picture::Picture()
:head(nullptr), tail(nullptr)
{
}

/*
Picture::picture(const Picture& other)
:head(nullptr)
{
    ListNode* copy(ListNode* head)
    {
        if(!head)
            return nullptr;
        return new ListNode{head->shape->clone(), copy(head->next)};
    }

    head = copy(other.head);
}
*/

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
    while(head)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp->shape;
        delete temp;
    }
 }
