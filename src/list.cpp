#include <iostream>
#include "list.hpp"

using namespace std;
using list::Node;


Node* list::from_string(const char* s)
{
    if (!s[0])
        return nullptr;
    return new Node{s[0], from_string(s+1)};
}

void list::free(Node* head)
{
    if(!head)
        return;
    Node* temp = head;
    free(head->next);
    delete temp;
    return;
}

void list::print(ostream& out, Node* head)
{
    if(!head)
        return;
    out << head->data;
    print(out, head->next);
}

Node* list::copy(Node* head)
{
    if(!head)
        return nullptr;
    return new Node{head->data, copy(head->next)};
}

int list::compare(Node* lhs, Node* rhs)
{
    for(; lhs!=nullptr && rhs!=nullptr; lhs=lhs->next, rhs=rhs->next)
        if(lhs->data != rhs->data)
            return lhs->data - rhs->data;
    if(!lhs && !rhs)
        return 0;
    else if(!rhs)
        return 1;
    else
        return -1;
}

int list::compare(Node* lhs, Node* rhs, int n)
{
    for(; lhs!=nullptr && rhs!=nullptr && n>0; lhs=lhs->next, rhs=rhs->next, --n)
        if(lhs->data != rhs->data)
            return lhs->data - rhs->data;
    if(n == 0)
        return 0;
    else if(!lhs && !rhs)
        return 0;
    else if(!rhs)
        return 1;
    else
        return -1;
}

int list::length(Node* head)
{
    if(!head)
        return 0;
    return 1+length(head->next);
}

Node* list::reverse(Node* head)
{
    Node* rev = nullptr;
    for(Node* p=head; p!=nullptr; p=p->next)
        rev = new Node{p->data, rev};
    return rev;
}

Node* list::append(Node* lhs, Node* rhs)
{
    if(!lhs)
        return copy(rhs);
    Node* head = copy(lhs);
    last(head)->next = copy(rhs);
    return head;
}

int list::index(Node* head, Node* node)
{
    if(!head)
        return 0;
    int i = 0;
    for(Node* p=head; p!=nullptr; p=p->next, ++i)
        if(p == node)
            return i;
    return -1;
} 

Node* list::find_char(Node* head, char c)
{
    if(!head)
        return nullptr;
    return head->data==c ? head : find_char(head->next, c);
}

Node* list::find_list (Node* haystack, Node* needle)
{
	int len = length(needle);
	if (len == 0)
		return haystack;
    if (!haystack)
		return nullptr;
	for(Node* p=haystack; p!=nullptr; p=p->next)
		if(compare(p, needle, len) == 0)
			return p;
	return nullptr;
}

Node* list::nth(Node* head, int n)
{
	if (n == 0)
		return head;
	return nth(head->next, n-1);
}

Node* list::last(Node* head)
{
    Node* p = head;
    for(; p->next!=nullptr; p=p->next) {}
    return p;
}
