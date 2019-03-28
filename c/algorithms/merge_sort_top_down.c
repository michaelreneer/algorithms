#include "merge_sort_top_down.h"

#include <stdlib.h>

static void merge(int array[],
                  int temp[],
                  size_t low,
                  size_t middle,
                  size_t high) {
  // Copy both haves of array to temp.
  for (size_t i = low; i < high + 1; ++i) {
    temp[i] = array[i];
  }

  // Copy the next largest element from temp to array.
  size_t i = low;
  size_t j = low;
  size_t k = middle + 1;
  while (j < middle + 1 && k < high + 1) {
    if (temp[j] < temp[k]) {
      array[i] = temp[j];
      ++j;
    } else {
      array[i] = temp[k];
      ++k;
    }
    ++i;
  }

  // Copy the remaining elements from temp to array.
  while (j < middle + 1) {
    array[i] = temp[j];
    ++i;
    ++j;
  }
}

static void merge_sort_top_down_internal(int array[],
                                         int temp[],
                                         size_t low,
                                         size_t high) {
  if (low >= high) {
    return;
  }
  size_t middle = low + (high - low) / 2;
  merge_sort_top_down_internal(array, temp, low, middle);
  merge_sort_top_down_internal(array, temp, middle + 1, high);
  merge(array, temp, low, middle, high);
}

void merge_sort_top_down(int array[], size_t length) {
  if (length == 0) {
    return;
  }

  int* temp = malloc(length * sizeof(int));
  merge_sort_top_down_internal(array, temp, 0, length - 1);
  free(temp);
}
