#include "test_fibonacci_recursive.h"

#include "fibonacci_recursive.h"
#include "testc.h"

static void test_fibonacci_recursive_with_zero(void) {
  unsigned int number = 0;
  unsigned int result = fibonacci_recursive(number);
  test_assert(result == 0);
}

static void test_fibonacci_recursive_with_one(void) {
  unsigned int number = 1;
  unsigned int result = fibonacci_recursive(number);
  test_assert(result == 1);
}

static void test_fibonacci_recursive_with_two(void) {
  unsigned int number = 2;
  unsigned int result = fibonacci_recursive(number);
  test_assert(result == 1);
}

static void test_fibonacci_recursive_with_three(void) {
  unsigned int number = 3;
  unsigned int result = fibonacci_recursive(number);
  test_assert(result == 2);
}

static void test_fibonacci_recursive_with_four(void) {
  unsigned int number = 4;
  unsigned int result = fibonacci_recursive(number);
  test_assert(result == 3);
}

static void test_fibonacci_recursive_with_five(void) {
  unsigned int number = 5;
  unsigned int result = fibonacci_recursive(number);
  test_assert(result == 5);
}

static void test_fibonacci_recursive_with_twenty(void) {
  unsigned int number = 20;
  unsigned int result = fibonacci_recursive(number);
  test_assert(result == 6765);
}

void test_fibonacci_recursive(void) {
  test(test_fibonacci_recursive_with_zero);
  test(test_fibonacci_recursive_with_one);
  test(test_fibonacci_recursive_with_two);
  test(test_fibonacci_recursive_with_three);
  test(test_fibonacci_recursive_with_four);
  test(test_fibonacci_recursive_with_five);
  test(test_fibonacci_recursive_with_twenty);
}
