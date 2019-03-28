#include "merge_sort_bottom_up.h"

#include <stdlib.h>

static int max(int a, int b) {
  return (a > b) ? a : b;
}

static void merge(int array[], int temp[], int low, int middle, int high) {
  // Copy both haves of array to temp.
  for (int i = low; i < high + 1; ++i) {
    temp[i] = array[i];
  }

  // Copy the next largest element from temp to array.
  int i = low;
  int j = low;
  int k = middle + 1;
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

static void merge_sort_bottom_up_internal(int array[], int temp[], int length) {
  for (int i = 1; i < length; i = i * 2) {
    for (int j = length - 1 - i; j >= 0; j = j - i * 2) {
      merge(array, temp, max(j - i + 1, 0), j, j + i);
    }
  }
}

void merge_sort_bottom_up(int array[], int length) {
  if (length == 0) {
    return;
  }

  int* temp = malloc((size_t)length * sizeof(int));
  merge_sort_bottom_up_internal(array, temp, length);
  free(temp);
}
