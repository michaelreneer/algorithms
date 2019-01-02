#include "quick_sort.h"

static void swap(int* i, int* j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}

static size_t partition(int array[], size_t low, size_t high) {
  size_t middle = low + (high - low) / 2;
  int pivot = array[middle];
  size_t i = low - 1;
  size_t j = high + 1;
  while (1) {
    do {
      ++i;
    } while (array[i] < pivot);
    do {
      --j;
    } while (array[j] > pivot);
    if (i >= j) {
      return j;
    }
    swap(array + i, array + j);
  }
}

static void quick_sort_internal(int array[], size_t low, size_t high) {
  if (low >= high) {
    return;
  }
  size_t index = partition(array, low, high);
  quick_sort_internal(array, low, index);
  quick_sort_internal(array, index + 1, high);
}

void quick_sort(int array[], size_t length) {
  if (length == 0) {
    return;
  }

  quick_sort_internal(array, 0, length - 1);
}
