#include <iostream>
using namespace std;
#include "letter_count.h"

constexpr int N_CHARS = ('Z'-'A'+1);  // will be 26

int main()
{
    int arr[N_CHARS] = {0};
    string line;

    while(getline(cin, line))
    {
        count(line, arr);
    }
    print_counts(arr, N_CHARS);
}
