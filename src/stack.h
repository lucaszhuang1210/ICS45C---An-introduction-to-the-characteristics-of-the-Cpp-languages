#include <iostream>
using namespace std;

constexpr int STK_MAX = 1000;

class Stack
{
    int _top;
    char buf[STK_MAX];
public:
    //constructs this Stack
    Stack()
    {
        _top = -1;
    }
    //adds c to top Stack
    void push(char c)
    {
        if(!isFull())
        {
            ++_top;
            buf[_top] = c;
        }
    }
    //removes and returns top char
    char pop()
    {
        if(!isEmpty())
        {
            return buf[_top--];
        }else{
            cout << "Stack is empty" << endl;
            return '@';
        }
    }
    // peeks at the top char and returns w/o removing
    char top()
    {
        if(isEmpty())
        {
            cout << "Stack is empty" << endl;
            return '@';
        }else{
            return buf[_top];
        }
    }
    //returns true if empty
    bool isEmpty()
    {
        return _top == -1;
    }
    // returns true if full
    bool isFull()
    {
        return _top == STK_MAX - 1;
    }
};

// pushes all the chars from string line onto the Stack stk
void push_all(Stack &stk, string line)
{
    int line_length = line.length();
    for(int i=0; i<line_length; ++i)
    {
        stk.push(line.at(i));
    }
}

// pops chars from stk and prints to cout
// all chars will be on the same line without any extra spaces
void pop_all(Stack &stk)
{
    string output;
    while(!stk.isEmpty())
    {
        output = output + stk.pop();
    }
    cout << output << endl;
}
