#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../app.h"
#include "unity.h"


void setUp(void) {}

void tearDown(void) {}

void test_start(void) {
    string str1 = new("Hello, world!");
    string str2 = new(NULL);
    TEST_ASSERT_EQUAL_STRING("Hello, world!", str1.data);
    TEST_ASSERT_EQUAL_STRING("", str2.data);
    clear(&str1);
    clear(&str2);
}

void test_concatenation(void) {
    string str1 = new("Hello");
    string str2 = new(", world!");
    string str3 = new(NULL);
    string result1 = concatenation(str1, str2);
    string result2 = concatenation(str2, str3);
    TEST_ASSERT_EQUAL_STRING("Hello, world!", result1.data);
    TEST_ASSERT_EQUAL_STRING(", world!", result2.data);
    clear(&str1);
    clear(&str2);
    clear(&str3);
    clear(&result1);
    clear(&result2);
}

void test_toupper(void) {
    string str1 = new("Hello, world!");
    string str2 = new(NULL);
    string result1 = upper(str1);
    string result2 = upper(str2);
    TEST_ASSERT_EQUAL_STRING("HELLO, WORLD!", result1.data);
    TEST_ASSERT_EQUAL_STRING("", result2.data);
    clear(&str1);
    clear(&str2);
    clear(&result1);
    clear(&result2);
}

void test_tolower(void) {
    string str1 = new("Hello, world!");
    string str2 = new(NULL);
    string result1 = lower(str1);
    string result2 = lower(str2);
    TEST_ASSERT_EQUAL_STRING("hello, world!", result1.data);
    TEST_ASSERT_EQUAL_STRING("", result2.data);
    clear(&str1);
    clear(&str2);
    clear(&result1);
    clear(&result2);
}

void test_substring(void) {
    string str = new("Hello, world!");
    string result1 = substring(str, 0, 4);
    string result2 = substring(str, 7, 11);
    string result3 = substring(str, 0, 12);
    string result4 = substring(str, 10, 13);
    string result5 = substring(str, -1, 3);
    string result6 = substring(str, 6, 4);
    TEST_ASSERT_EQUAL_STRING("Hello", result1.data);
    TEST_ASSERT_EQUAL_STRING("world", result2.data);
    TEST_ASSERT_EQUAL_STRING("Hello, world!", result3.data);
    TEST_ASSERT_EQUAL_STRING("", result4.data);
    TEST_ASSERT_EQUAL_STRING("", result5.data);
    TEST_ASSERT_EQUAL_STRING("", result6.data);
    clear(&str);
    clear(&result1);
    clear(&result2);
    clear(&result3);
    clear(&result4);
    clear(&result5);
    clear(&result6);
}

int run_tests(void) {
    UNITY_BEGIN();
    RUN_TEST(test_start);
    RUN_TEST(test_concatenation);
    RUN_TEST(test_toupper);
    RUN_TEST(test_tolower);
    RUN_TEST(test_substring);
    return UNITY_END();
}
