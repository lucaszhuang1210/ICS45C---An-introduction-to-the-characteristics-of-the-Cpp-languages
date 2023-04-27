#include <gtest/gtest.h>

#include "string.hpp"

//****************TEST static helper methods*********************
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
    EXPECT_EQ(String::strncmp("Hello", "HelloW", 5), 0);
    EXPECT_LT(String::strncmp("Hello", "HelloW", 6), 0);
    EXPECT_GT(String::strncmp("Hello", "", 8), 0);
    EXPECT_LT(String::strncmp("Hello", "HelloW", 8), 0);
    EXPECT_EQ(String::strncmp("W", "W", 2), 0);
}

TEST(StringFunction, reverse_cpy) {
    char result[10];
    String::reverse_cpy(result, "abc");
    EXPECT_STREQ(result, "cba");

    char oneChar[10];
    String::reverse_cpy(oneChar, "a");
    EXPECT_STREQ(oneChar, "a");

    char empty_str[10];
    String::reverse_cpy(empty_str, "");
    EXPECT_STREQ(empty_str, "");
}

TEST(StringFunction, strchr) {
    char s1[] = "This is a String";
    const char *p = String::strchr(s1, '1');
    EXPECT_EQ(p, nullptr);
    
    const char *p2 = String::strchr(s1, 's');
    EXPECT_EQ(p2, (s1+3));

    const char *p3 = String::strchr(s1, '\0');
    EXPECT_EQ(p3, (s1+String::strlen(s1)));
}

TEST(StringFunction, strstr) {
    char s1[] = "This is a String";
    const char *p = String::strstr(s1, "NOTHING");
    EXPECT_EQ(p, nullptr);
    
    const char *p2 = String::strstr(s1, "String");
    EXPECT_EQ(p2, (s1+10));

    //int len = String::strlen(s1);
    const char *p3 = String::strstr(s1, "");
    EXPECT_EQ(p3, s1);
}
