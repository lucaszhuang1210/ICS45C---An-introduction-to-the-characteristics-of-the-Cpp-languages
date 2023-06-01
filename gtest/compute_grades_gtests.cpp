include <gtest/gtest.h>

#include "compute_grades.hpp"

// TODO
TEST(GradebookTests, Extractor){
    string input = "Name Marge Simpson\n
                    Quiz 80\n
                    HW 70\n
                    Final 90\n";
    Gradebook b;
    gradebook >> b;

}
