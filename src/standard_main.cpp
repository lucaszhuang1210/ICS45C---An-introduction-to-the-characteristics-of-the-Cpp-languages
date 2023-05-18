#include <iostream>
#include <string>
#include "picture.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"
using namespace std;

constexpr int N_TESTS = 15;
constexpr int P1DEFAULT = 2 ;
constexpr int P2DEFAULT = 3;

void add_shapes(Picture& p, int i, int param1, int param2) 
{
    p.add(Circle{{0, 0}, "Circle_" + to_string(i), i*param1});
    p.add(Square{{0, 0}, "Square_" + to_string(i), i*param1});
    p.add(Triangle{{0, 0}, "Triangle_" + to_string(i), i*param1, i*param2});
    p.add(Rectangle{{0, 0}, "Rectangle_" + to_string(i), i*param1, i*param2});
}

int get_param(int num, int argc, char** argv, int def) 
{
return argc > num ? atoi(argv[num]) : def;
}

int main(int argc, char** argv)
{
    int param1 = get_param(1, argc, argv, P1DEFAULT);
    int param2 = get_param(2, argc, argv, P2DEFAULT);
    Picture collage;
    for (int i = 1; i<= N_TESTS; ++i)
        add_shapes(collage, i, param1, param2);
    cout << "Total Area = " << collage.total_area() << endl;
    collage.print_all(cout);
    collage.draw_all(cout);
}
