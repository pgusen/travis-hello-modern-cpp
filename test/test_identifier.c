//Include the test framework.
#include "../tools/Unity/src/unity.h"

//Include the header file with the declarations of the functions
#include "../identifier.h"

void setUp (void) {} /* Is run before every test, put unit init calls here. */
void tearDown (void) {} /* Is run after every test, put unit clean-up calls here. */

void test_length() {
    TEST_ASSERT_EQUAL(0, identifier("abcde"));
    TEST_ASSERT_EQUAL(1, identifier("abc5ef"));
    TEST_ASSERT_EQUAL(1, identifier(""));
}

void test_first_char() {
    TEST_ASSERT_EQUAL(0, identifier("aabc"));
    TEST_ASSERT_EQUAL(1, identifier("1abc"));
}

void test_alfanumeric() {
    TEST_ASSERT_EQUAL(0, identifier("e1d2"));
    TEST_ASSERT_EQUAL(1, identifier("a1b!"));
}