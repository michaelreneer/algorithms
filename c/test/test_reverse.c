#include "test_reverse.h"

#include "reverse.h"
#include "testc.h"

#include <string.h>

static void test_reverse_with_one_character(void) {
  char string[] = "a";
  reverse(string);
  char expected[] = "a";
  test_assert(strcmp(string, expected) == 0);
}

static void test_reverse_with_two_characters(void) {
  char string[] = "as";
  reverse(string);
  char expected[] = "sa";
  test_assert(strcmp(string, expected) == 0);
}

static void test_reverse_with_three_characters(void) {
  char string[] = "asd";
  reverse(string);
  char expected[] = "dsa";
  test_assert(strcmp(string, expected) == 0);
}

static void test_reverse_with_ten_characters(void) {
  char string[] = "asdfghjklz";
  reverse(string);
  char expected[] = "zlkjhgfdsa";
  test_assert(strcmp(string, expected) == 0);
}

static void test_reverse_with_equal_characters(void) {
  char string[] = "aaaaaaaaaa";
  reverse(string);
  char expected[] = "aaaaaaaaaa";
  test_assert(strcmp(string, expected) == 0);
}

static void test_reverse_with_no_characters(void) {
  char string[] = "";
  reverse(string);
  char expected[] = "";
  test_assert(strcmp(string, expected) == 0);
}

void test_reverse(void) {
  test(test_reverse_with_one_character);
  test(test_reverse_with_two_characters);
  test(test_reverse_with_three_characters);
  test(test_reverse_with_ten_characters);
  test(test_reverse_with_equal_characters);
  test(test_reverse_with_no_characters);
}
