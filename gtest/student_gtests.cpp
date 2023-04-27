#include <gtest/gtest.h>

#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
    char result[10];
    EXPECT_EQ(String::strncpy(result, "fooSTOP", 3), result);
    EXPECT_STREQ(result, "foo");
    
    EXPECT_EQ(String::strncpy(result, "a", 1), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strncpy(result, "", 0), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strcat) {
    char s1[20];
    String::strcpy(s1, "I am ");
    const char *s2 = {"Lucas"};
    EXPECT_EQ(String::strcat(s1, s2), s1);
    EXPECT_STREQ(s1, "I am Lucas");
    
    char result[10];
    String::strcpy(result, "");
    EXPECT_EQ(String::strcat(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcat(result, ""), result);
    EXPECT_STREQ(result, "a");
}

TEST(StringFunction, strncat) {
    char s1[20];
    String::strcpy(s1, "I am ");
    const char *s2 = {"LucasLUCAS"};
    EXPECT_EQ(String::strncat(s1, s2, 5), s1);
    EXPECT_STREQ(s1, "I am Lucas");
    
    char result[10];
    String::strcpy(result, "");
    EXPECT_EQ(String::strncat(result, "a", 1), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strncat(result, "", 0), result);
    EXPECT_STREQ(result, "a");
}

TEST(StringFunction, strcmp) {
    char s1[20];
    String::strcpy(s1, "I am ");
    const char *s2 = {"LucasLUCAS"};
    EXPECT_LT(String::strcmp(s1, s2), 0);
    
    char result[10];
    String::strcpy(result, "");
    EXPECT_GT(String::strcmp(s1, result), 0);


    EXPECT_EQ(String::strcmp("", ""), 0);
}

TEST(StringFunction, strncmp) {
    char s1[20];
    String::strcpy(s1, "I am ");
    const char *s2 = {"I am LucasLUCAS"};
    EXPECT_EQ(String::strncmp(s1, s2, 5), 0);
    
    char result[10];
    String::strcpy(result, "I");
    EXPECT_EQ(String::strncmp(s1, result, 1), 0);


    EXPECT_EQ(String::strncmp("", "", 0), 0);
}

TEST(StringFunction, reverse_cpy) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strchr) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strstr) {
    EXPECT_TRUE(false);
}
