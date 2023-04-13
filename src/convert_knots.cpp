#include <iostream>
using namespace std;
#include "convert_knots.h"

int main()
{
    int knots = 0;
    cout << "Enter integer speed in knots: ";
    cin >> knots;
    cout << "Speed in miles per minutes is " << knots_to_miles_per_minute(knots)<< endl;

    return 0;

}
