#include <fstream>

#include "compute_grades.hpp"

using namespace std;

int main()
{
    ifstream gradebook{"gradebook.txt"};
    Gradebook b;
    gradebook >> b;

    b.validate();
    b.compute_grades();
    b.sort();

    ofstream course_greades{"course_grades.txt"};
    course_greades << b;
}
