#include "process_numbers.hpp"
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void split_odd_even(istream & numbers, ostream & odds, ostream& evens)
{
    vector<int> nums;
    copy(istream_iterator<int>(numbers), istream_iterator<int>(), back_inserter(nums));
    ranges::sort(nums);
    ranges::copy_if(nums, ostream_iterator<int>(odds, " "), 
                                        [](int n) { return n%2 != 0; });
    ranges::copy_if(nums, ostream_iterator<int>(evens, "\n"), 
                                        [](int n) { return n%2 == 0; });
}
