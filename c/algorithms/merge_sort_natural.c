#include "merge_sort_natural.h"

#include <stdbool.h>
#include <stdlib.h>

static void merge(const int src[],
                  int dest[],
                  size_t low,
                  size_t high,
                  bool ascending) {
  // Copy the next largest element from src to dest.
  size_t i = (ascending) ? low : high;
  size_t j = low;
  size_t k = high;
  while (j <= k) {
    if (src[j] <= src[k]) {
      dest[i] = src[j];
      ++j;
    } else {
      dest[i] = src[k];
      --k;
    }
    if (ascending) {
      ++i;
    } else {
      --i;
    }
  }
}

static bool merge_runs(const int src[], int dest[], size_t length) {
  bool ascending = true;
  size_t i = 0;
  size_t j = 0;
  while (i < length) {
    j = i;
    int element = src[i];
    ++i;
    while (i < length && element <= src[i]) {
      element = src[i];
      ++i;
    }
    while (i < length && element >= src[i]) {
      element = src[i];
      ++i;
    }
    merge(src, dest, j, i - 1, ascending);
    ascending = !ascending;
  }
  return (j == 0);
}

static void merge_sort_natural_internal(int array[],
                                        int temp[],
                                        size_t length) {
  bool unsorted = true;
  while (unsorted) {
    merge_runs(array, temp, length);
    unsorted = !merge_runs(temp, array, length);
  }
}

void merge_sort_natural(int array[], size_t length) {
  if (length == 0) {
    return;
  }

  int* temp = malloc(length * sizeof(int));
  merge_sort_natural_internal(array, temp, length);
  free(temp);
}
