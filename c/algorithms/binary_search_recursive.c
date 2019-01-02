#include "binary_search_recursive.h"

static int binary_search_recursive_internal(const int array[],
                                            int element,
                                            int low,
                                            int high) {
  if (low > high) {
    return -1;
  }
  int middle = low + (high - low) / 2;
  if (array[middle] < element) {
    return binary_search_recursive_internal(array, element, middle + 1, high);
  } else if (array[middle] > element) {
    return binary_search_recursive_internal(array, element, low, middle - 1);
  } else {
    return middle;
  }
}

int binary_search_recursive(const int array[], int length, int element) {
  return binary_search_recursive_internal(array, element, 0, length - 1);
}
