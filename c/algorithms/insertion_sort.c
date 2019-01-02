#include "insertion_sort.h"

void insertion_sort(int array[], size_t length) {
  for (size_t i = 1; i < length; ++i) {
    int temp = array[i];
    size_t j = i;
    while (j > 0 && array[j - 1] > temp) {
      array[j] = array[j - 1];
      --j;
    }
    array[j] = temp;
  }
}
