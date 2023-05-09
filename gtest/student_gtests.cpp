#include <gtest/gtest.h>

#include "list.hpp"

using namespace std;
using list::Node;

TEST(ListTests, FromStringBasic) {
    Node* const foo_list_head = list::from_string("foo");
    Node* foo_list = foo_list_head;

    EXPECT_EQ(foo_list->data, 'f');
    // ASSERT instead of EXPECT means: end the test here if this fails, do not try to continue
    // running. This is useful to prevent early crashes.
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_EQ(foo_list->next, nullptr);

    list::free(foo_list_head);
}

TEST(ListTests, Length) {
    Node* const head = list::from_string("foo");
    EXPECT_EQ(list::length(head), 3);
    list::free(head);

    Node* const l1 = list::from_string("");
    EXPECT_EQ(list::length(l1), 0);
    list::free(l1);
}

// Add remaining tests below. All tests should follow
// the format of `TEST(ListTests, <TestName>){}`.

/*
TEST(ListTests, Print) {
    Node* const l1 = list::from_string("foo");
    list::print(cout, l1);
    list::free(l1);

    Node* const l2 = list::from_string("");
    list::print(cout, l2);
    list::free(l2);
}
*/

TEST(ListTests, Copy) {
    Node* const l1 = list::from_string("");
    EXPECT_EQ(list::length(list::copy(l1)), length(l1));
    list::free(l1);

    Node* const l2 = list::from_string("foo");
    Node* output = copy(l2);

    EXPECT_EQ(output->data, l2->data);
    EXPECT_EQ(length(output), length(l2));

    list::free(l2);
    list::free(output);
}

TEST(ListTests, Compare) {
    Node* const l1 = list::from_string("foo");
    Node* const l2 = list::from_string("foo");
    Node* const l3 = list::from_string("foo ");
    Node* const l4 = list::from_string("");

    EXPECT_EQ(list::compare(l1, l2), 0);
    EXPECT_LT(list::compare(l1, l3), 0);
    EXPECT_GT(list::compare(l1, l4), 0);

    list::free(l1);
    list::free(l2);
    list::free(l3);
    list::free(l4);
}

TEST(ListTests, NCompare) {
    Node* const l1 = list::from_string("foo");
    Node* const l2 = list::from_string("foo");
    Node* const l3 = list::from_string("foo ");
    Node* const l4 = list::from_string("");

    EXPECT_EQ(list::compare(l1, l2, 3), 0);
    EXPECT_EQ(list::compare(l1, l3, 3), 0);
    EXPECT_GT(list::compare(l1, l4, 3), 0);

    list::free(l1);
    list::free(l2);
    list::free(l3);
    list::free(l4);
}


