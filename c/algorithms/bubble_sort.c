#include "bubble_sort.h"

#include <stdbool.h>

static void swap(int* i, int* j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}

void bubble_sort(int array[], size_t length) {
  if (length == 0) {
    return;
  }

  bool unsorted = true;
  size_t j = 1;
  while (unsorted) {
    unsorted = false;
    for (size_t i = 0; i < length - j; ++i) {
      if (array[i] > array[i + 1]) {
        swap(array + i, array + i + 1);
        unsorted = true;
      }
    }
    ++j;
  }
}
