#include "test_count_set_bits.h"

#include "count_set_bits.h"
#include "testc.h"

static void test_count_set_bits_with_zero(void) {
  unsigned int number = 0;
  unsigned int count = count_set_bits(number);
  test_assert(count == 0);
}

static void test_count_set_bits_with_one(void) {
  unsigned int number = 1;
  unsigned int count = count_set_bits(number);
  test_assert(count == 1);
}

static void test_count_set_bits_with_two(void) {
  unsigned int number = 2;
  unsigned int count = count_set_bits(number);
  test_assert(count == 1);
}

static void test_count_set_bits_with_three(void) {
  unsigned int number = 3;
  unsigned int count = count_set_bits(number);
  test_assert(count == 2);
}

static void test_count_set_bits_with_four(void) {
  unsigned int number = 4;
  unsigned int count = count_set_bits(number);
  test_assert(count == 1);
}

static void test_count_set_bits_with_five(void) {
  unsigned int number = 5;
  unsigned int count = count_set_bits(number);
  test_assert(count == 2);
}

static void test_count_set_bits_with_twenty(void) {
  unsigned int number = 20;
  unsigned int count = count_set_bits(number);
  test_assert(count == 2);
}

void test_count_set_bits(void) {
  test(test_count_set_bits_with_zero);
  test(test_count_set_bits_with_one);
  test(test_count_set_bits_with_two);
  test(test_count_set_bits_with_three);
  test(test_count_set_bits_with_four);
  test(test_count_set_bits_with_five);
  test(test_count_set_bits_with_twenty);
}
