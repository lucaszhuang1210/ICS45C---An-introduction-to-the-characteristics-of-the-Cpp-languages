#include <fstream>
#include <iostream>

#include "process_numbers.hpp"

int main() {
    std::ifstream input{"src/rand_numbers.txt"};
    std::ofstream odds{"odds.txt"};
    std::ofstream evens{"evens.txt"};
    split_odd_even(input, odds, evens);
}
