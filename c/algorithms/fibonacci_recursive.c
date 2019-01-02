#include "fibonacci_recursive.h"

unsigned int fibonacci_recursive(unsigned int number) {
  if (number == 0 || number == 1) {
    return number;
  }
  return fibonacci_recursive(number - 1) + fibonacci_recursive(number - 2);
}
