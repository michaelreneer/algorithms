#include "test_linear_search.h"

#include "linear_search.h"
#include "testc.h"

#include <stddef.h>
#include <stdlib.h>

static void test_linear_search_returns_first_index(void) {
  int length = 3;
  int array[] = {1, 2, 3};
  int element = 1;
  int index = linear_search(array, length, element);
  test_assert(index == 0);
}

static void test_linear_search_returns_middle_index(void) {
  int length = 3;
  int array[] = {1, 2, 3};
  int element = 2;
  int index = linear_search(array, length, element);
  test_assert(index == 1);
}

static void test_linear_search_returns_last_index(void) {
  int length = 3;
  int array[] = {1, 2, 3};
  int element = 3;
  int index = linear_search(array, length, element);
  test_assert(index == 2);
}

static void test_linear_search_returns_no_index(void) {
  int length = 3;
  int array[] = {1, 2, 3};
  int element = 10;
  int index = linear_search(array, length, element);
  test_assert(index == -1);
}

static void test_linear_search_with_one_element_returns_index(void) {
  int length = 1;
  int array[] = {1};
  int element = 1;
  int index = linear_search(array, length, element);
  test_assert(index == 0);
}

static void test_linear_search_with_heap_elements(void) {
  int length = 10;
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int element = 1;
  int index = linear_search(array, length, element);
  test_assert(index == 0);
}

static void test_linear_search_with_stack_elements(void) {
  int length = 10;
  int* array = malloc((size_t)length * sizeof(int));
  for (int i = 0; i < length; ++i) {
    array[i] = i + 1;
  }
  int element = 1;
  int index = linear_search(array, length, element);
  test_assert(index == 0);
  free(array);
}

void test_linear_search(void) {
  test(test_linear_search_returns_first_index);
  test(test_linear_search_returns_middle_index);
  test(test_linear_search_returns_last_index);
  test(test_linear_search_returns_no_index);
  test(test_linear_search_with_one_element_returns_index);
  test(test_linear_search_with_heap_elements);
  test(test_linear_search_with_stack_elements);
}
