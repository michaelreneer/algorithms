#include "binary_search_iterative.h"

int binary_search_iterative(const int array[], int length, int element) {
  int low = 0;
  int high = length - 1;
  while (low <= high) {
    int middle = low + (high - low) / 2;
    if (array[middle] < element) {
      low = middle + 1;
    } else if (array[middle] > element) {
      high = middle - 1;
    } else {
      return middle;
    }
  }
  return -1;
}
