#include <gtest/gtest.h>

#include <string>

#include "array.hpp"

using namespace std;

TEST(ArrayTests, Length) {
    Array<int> arr{3};
    EXPECT_EQ(arr.length(), 3);

    Array<string> arr2{10};
    EXPECT_EQ(arr2.length(), 10);

    EXPECT_EQ(Array<double>{}.length(), 0);
}

TEST(ArrayTests, Subscript) {
    Array<double> arr{10};
    arr[0] = 3.0;
    arr[3] = 5.5;
    EXPECT_EQ(arr[0], 3.0);
    EXPECT_EQ(arr[3], 5.5);

    Array<string> arr2{10};
    arr2[0] = string("Hi");
    EXPECT_EQ(arr2[0], "Hi");
}

TEST(ArrayTests, Print) {
    stringstream out;

    Array<string> arr{2};
    arr[0] = string("Hello");
    arr[1] = string("World");

    out << arr;

    EXPECT_EQ(out.str(), "   Hello   World");
}

TEST(ArrayTests, Read) {
    stringstream in{"Hello World 3 4"};

    Array<string> arr{3};
    in >> arr;

    EXPECT_EQ(arr[0], "Hello");
    EXPECT_EQ(arr[1], "World");
    EXPECT_EQ(arr[2], "3");
}

TEST(ArrayTests, Fill) {
    Array<string> arr{10};
    arr.fill("Hi");
    EXPECT_EQ(arr[0], "Hi");
}

TEST(ArrayTests, FillWithFn) {
    Array<int> arr{10};
    arr.fill_with_fn([](int i) { return i*i; }(3));
    EXPECT_EQ(arr[0], 9);
}

