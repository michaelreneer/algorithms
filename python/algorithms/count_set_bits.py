#!/usr/bin/env python


def count_set_bits(number):
  """Returns the number of set bits in the number.

  Iterates through the bits of an integer and increment the count if the bit is
  set.

  * O(n) time complexity
  * O(1) space complexity

  Args:
    number: An integer.
  Raises:
    TypeError: If number is not an integer.
  """
  if not isinstance(number, int):
    raise TypeError('\'{}\' object is not an integer'.format(
        type(number).__name__))

  count = 0
  while number > 0:
    count += number & 1
    number = number >> 1
  return count
