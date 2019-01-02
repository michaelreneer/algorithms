#include "selection_sort.h"

static void swap(int* i, int* j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}

void selection_sort(int array[], size_t length) {
  for (size_t i = 0; i < length; ++i) {
    size_t low = i;
    for (size_t j = i + 1; j < length; ++j) {
      if (array[j] < array[low]) {
        low = j;
      }
    }
    if (i != low) {
      swap(array + i, array + low);
    }
  }
}
