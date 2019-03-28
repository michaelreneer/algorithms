#include "merge_sort_bottom_up.h"

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

static void merge_sort_bottom_up_internal(int array[],
                                          int temp[],
                                          size_t length) {
  for (size_t i = 1; i < length; i = i * 2) {
    size_t j = length - 1 - i;

    for (;;) {
      // Do not assign a negative value to an unsigned type.
      size_t low = 0;
      if (j >= i - 1) {
        low = j - i + 1;
      }

      size_t middle = j;
      size_t high = j + i;
      merge(array, temp, low, middle, high);

      // Do not assign a negative value to an unsigned type.
      if (j < i * 2) {
        break;
      }
      j = j - i * 2;
    }
  }
}

void merge_sort_bottom_up(int array[], size_t length) {
  if (length == 0) {
    return;
  }

  int* temp = malloc(length * sizeof(int));
  merge_sort_bottom_up_internal(array, temp, length);
  free(temp);
}
