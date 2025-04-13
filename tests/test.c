#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../app.h"
#include "unity.h"

void setUp(void) {

}

void tearDown(void) {

}

void test_start(void) {
    string str = new(str, 13);
    strncpy(str.data, "Hello, world!", str.len+1);
    TEST_ASSERT_EQUAL_STRING("Hello, world!", str.data);
    TEST_ASSERT_EQUAL(13, str.len);
    clear(&str);
}

void test_concatenation(void) {
    string str1 = new(str1, 5);
    string str2 = new(str1, 8);
    strncpy(str1.data, "Hello", str1.len+1);
    strncpy(str2.data, ", world!", str2.len+1);
    string result = concatenation(str1, str2);
    TEST_ASSERT_EQUAL_STRING("Hello, world!", result.data);
    TEST_ASSERT_EQUAL(13, result.len);
    clear(&str1);
    clear(&str2);
    clear(&result);
}

void test_toupper(void) {
    string str = new(str, 13);
    strncpy(str.data, "Hello, world!", str.len+1);
    string result = upper(str);
    TEST_ASSERT_EQUAL_STRING("HELLO, WORLD!", result.data);
    clear(&str);
    clear(&result);
}

void test_tolower(void) {
    string str = new(str, 13);
    strncpy(str.data, "Hello, world!", str.len+1);
    string result = lower(str);
    TEST_ASSERT_EQUAL_STRING("hello, world!", result.data);
    clear(&str);
    clear(&result);
}

void test_substring(void) {
    string result;
    string str = new(str, 13);
    strncpy(str.data, "Hello, world!", str.len+1);
    result = substring(str, 7, 11);
    TEST_ASSERT_EQUAL_STRING("world", result.data);
    result = substring(str, 0, 4);
    TEST_ASSERT_EQUAL_STRING("Hello", result.data);
    clear(&str);
    clear(&result);
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
