#include "linear_search.h"

int linear_search(const int array[], int length, int element) {
  for (int i = 0; i < length; ++i) {
    if (array[i] == element) {
      return i;
    }
  }
  return -1;
}
