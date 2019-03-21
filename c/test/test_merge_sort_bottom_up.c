#include "test_merge_sort_bottom_up.h"

#include "merge_sort_bottom_up.h"
#include "testc.h"

#include <stddef.h>
#include <string.h>

static void test_merge_sort_bottom_up_with_one_element(void) {
  int length = 1;
  int array[] = {1};
  merge_sort_bottom_up(array, length);
  int expected[] = {1};
  test_assert(memcmp(array, expected, (size_t)length * sizeof(int)) == 0);
}

static void test_merge_sort_bottom_up_with_two_elements_1(void) {
  int length = 2;
  int array[] = {1, 2};
  merge_sort_bottom_up(array, length);
  int expected[] = {1, 2};
  test_assert(memcmp(array, expected, (size_t)length * sizeof(int)) == 0);
}

static void test_merge_sort_bottom_up_with_two_elements_2(void) {
  int length = 2;
  int array[] = {2, 1};
  merge_sort_bottom_up(array, length);
  int expected[] = {1, 2};
  test_assert(memcmp(array, expected, (size_t)length * sizeof(int)) == 0);
}

static void test_merge_sort_bottom_up_with_three_elements_1(void) {
  int length = 3;
  int array[] = {1, 2, 3};
  merge_sort_bottom_up(array, length);
  int expected[] = {1, 2, 3};
  test_assert(memcmp(array, expected, (size_t)length * sizeof(int)) == 0);
}

static void test_merge_sort_bottom_up_with_three_elements_2(void) {
  int length = 3;
  int array[] = {1, 3, 2};
  merge_sort_bottom_up(array, length);
  int expected[] = {1, 2, 3};
  test_assert(memcmp(array, expected, (size_t)length * sizeof(int)) == 0);
}

static void test_merge_sort_bottom_up_with_three_elements_3(void) {
  int length = 3;
  int array[] = {2, 1, 3};
  merge_sort_bottom_up(array, length);
  int expected[] = {1, 2, 3};
  test_assert(memcmp(array, expected, (size_t)length * sizeof(int)) == 0);
}

static void test_merge_sort_bottom_up_with_three_elements_4(void) {
  int length = 3;
  int array[] = {2, 3, 1};
  merge_sort_bottom_up(array, length);
  int expected[] = {1, 2, 3};
  test_assert(memcmp(array, expected, (size_t)length * sizeof(int)) == 0);
}

static void test_merge_sort_bottom_up_with_three_elements_5(void) {
  int length = 3;
  int array[] = {3, 1, 2};
  merge_sort_bottom_up(array, length);
  int expected[] = {1, 2, 3};
  test_assert(memcmp(array, expected, (size_t)length * sizeof(int)) == 0);
}

static void test_merge_sort_bottom_up_with_three_elements_6(void) {
  int length = 3;
  int array[] = {3, 2, 1};
  merge_sort_bottom_up(array, length);
  int expected[] = {1, 2, 3};
  test_assert(memcmp(array, expected, (size_t)length * sizeof(int)) == 0);
}

static void test_merge_sort_bottom_up_with_ascending_elements(void) {
  int length = 10;
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  merge_sort_bottom_up(array, length);
  int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  test_assert(memcmp(array, expected, (size_t)length * sizeof(int)) == 0);
}

static void test_merge_sort_bottom_up_with_descending_elements(void) {
  int length = 10;
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  merge_sort_bottom_up(array, length);
  int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  test_assert(memcmp(array, expected, (size_t)length * sizeof(int)) == 0);
}

static void test_merge_sort_bottom_up_with_equal_elements(void) {
  int length = 10;
  int array[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  merge_sort_bottom_up(array, length);
  int expected[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  test_assert(memcmp(array, expected, (size_t)length * sizeof(int)) == 0);
}

void test_merge_sort_bottom_up(void) {
  test(test_merge_sort_bottom_up_with_one_element);
  test(test_merge_sort_bottom_up_with_two_elements_1);
  test(test_merge_sort_bottom_up_with_two_elements_2);
  test(test_merge_sort_bottom_up_with_three_elements_1);
  test(test_merge_sort_bottom_up_with_three_elements_2);
  test(test_merge_sort_bottom_up_with_three_elements_3);
  test(test_merge_sort_bottom_up_with_three_elements_4);
  test(test_merge_sort_bottom_up_with_three_elements_5);
  test(test_merge_sort_bottom_up_with_three_elements_6);
  test(test_merge_sort_bottom_up_with_ascending_elements);
  test(test_merge_sort_bottom_up_with_descending_elements);
  test(test_merge_sort_bottom_up_with_equal_elements);
}
