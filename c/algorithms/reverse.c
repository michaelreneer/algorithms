#include "reverse.h"

#include <stddef.h>
// #include <string.h>

static size_t strlen(const char* string) {
  size_t length = 0;
  while (string[length] != '\0') {
    ++length;
  }
  return length;
}

static void swap(char* i, char* j) {
  char temp = *i;
  *i = *j;
  *j = temp;
}

void reverse(char* string) {
  size_t length = strlen(string);
  if (length == 0) {
    return;
  }
  size_t low = 0;
  size_t high = length - 1;
  while (low < high) {
    swap(string + low, string + high);
    ++low;
    --high;
  }
}
