#include "count_set_bits.h"

unsigned int count_set_bits(unsigned int number) {
  unsigned int count = 0;
  while (number > 0) {
    count += number & 1u;
    number = number >> 1u;
  }
  return count;
}
