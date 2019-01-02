#include "fibonacci_iterative.h"

unsigned int fibonacci_iterative(unsigned int number) {
  if (number == 0 || number == 1) {
    return number;
  }
  unsigned int a = 0;
  unsigned int b = 1;
  for (unsigned int i = 2; i <= number; ++i) {
    unsigned int c = a + b;
    a = b;
    b = c;
  }
  return b;
}
