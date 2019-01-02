#include "test_bubble_sort.h"

#include "bubble_sort.h"
#include "testc.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static void test_bubble_sort_with_one_element(void) {
  size_t length = 1;
  int array[] = {1};
  bubble_sort(array, length);
  int expected[] = {1};
  test_assert(memcmp(array, expected, length * sizeof(int)) == 0);
}

static void test_bubble_sort_with_two_elements_1(void) {
  size_t length = 2;
  int array[] = {1, 2};
  bubble_sort(array, length);
  int expected[] = {1, 2};
  test_assert(memcmp(array, expected, length * sizeof(int)) == 0);
}

static void test_bubble_sort_with_two_elements_2(void) {
  size_t length = 2;
  int array[] = {2, 1};
  bubble_sort(array, length);
  int expected[] = {1, 2};
  test_assert(memcmp(array, expected, length * sizeof(int)) == 0);
}

static void test_bubble_sort_with_three_elements_1(void) {
  size_t length = 3;
  int array[] = {1, 2, 3};
  bubble_sort(array, length);
  int expected[] = {1, 2, 3};
  test_assert(memcmp(array, expected, length * sizeof(int)) == 0);
}

static void test_bubble_sort_with_three_elements_2(void) {
  size_t length = 3;
  int array[] = {1, 3, 2};
  bubble_sort(array, length);
  int expected[] = {1, 2, 3};
  test_assert(memcmp(array, expected, length * sizeof(int)) == 0);
}

static void test_bubble_sort_with_three_elements_3(void) {
  size_t length = 3;
  int array[] = {2, 1, 3};
  bubble_sort(array, length);
  int expected[] = {1, 2, 3};
  test_assert(memcmp(array, expected, length * sizeof(int)) == 0);
}

static void test_bubble_sort_with_three_elements_4(void) {
  size_t length = 3;
  int array[] = {2, 3, 1};
  bubble_sort(array, length);
  int expected[] = {1, 2, 3};
  test_assert(memcmp(array, expected, length * sizeof(int)) == 0);
}

static void test_bubble_sort_with_three_elements_5(void) {
  size_t length = 3;
  int array[] = {3, 1, 2};
  bubble_sort(array, length);
  int expected[] = {1, 2, 3};
  test_assert(memcmp(array, expected, length * sizeof(int)) == 0);
}

static void test_bubble_sort_with_three_elements_6(void) {
  size_t length = 3;
  int array[] = {3, 2, 1};
  bubble_sort(array, length);
  int expected[] = {1, 2, 3};
  test_assert(memcmp(array, expected, length * sizeof(int)) == 0);
}

static void test_bubble_sort_with_ascending_elements(void) {
  size_t length = 10;
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  bubble_sort(array, length);
  int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  test_assert(memcmp(array, expected, length * sizeof(int)) == 0);
}

static void test_bubble_sort_with_descending_elements(void) {
  size_t length = 10;
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  bubble_sort(array, length);
  int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  test_assert(memcmp(array, expected, length * sizeof(int)) == 0);
}

static void test_bubble_sort_with_equal_elements(void) {
  size_t length = 10;
  int array[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  bubble_sort(array, length);
  int expected[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  test_assert(memcmp(array, expected, length * sizeof(int)) == 0);
}

static void test_bubble_sort_with_no_elements(void) {
  size_t length = 0;
  int* array = malloc(length * sizeof(int));
  bubble_sort(array, length);
  int* expected = malloc(length * sizeof(int));
  test_assert(memcmp(array, expected, length * sizeof(int)) == 0);
  free(array);
  free(expected);
}

void test_bubble_sort(void) {
  test(test_bubble_sort_with_one_element);
  test(test_bubble_sort_with_two_elements_1);
  test(test_bubble_sort_with_two_elements_2);
  test(test_bubble_sort_with_three_elements_1);
  test(test_bubble_sort_with_three_elements_2);
  test(test_bubble_sort_with_three_elements_3);
  test(test_bubble_sort_with_three_elements_4);
  test(test_bubble_sort_with_three_elements_5);
  test(test_bubble_sort_with_three_elements_6);
  test(test_bubble_sort_with_ascending_elements);
  test(test_bubble_sort_with_descending_elements);
  test(test_bubble_sort_with_equal_elements);
  test(test_bubble_sort_with_no_elements);
}
