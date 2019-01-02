#!/usr/bin/env python


def reverse(iterable):
  """Reverses the iterable.

  Iterate through the collection with two pointers, one increasing from the
  beginning of the collection and the other decreasing from the end of the
  collection, and swap the items at the respective pointers. Iterations through
  the collection are repeated until the pointer that is increasing is no longer
  less than the pointer that is decreasing.

  * O(n) time complexity
  * O(1) space complexity

  Args:
    iterable: A collection that is iterable.
  Raises:
    TypeError: If iterable is not iterable.
  """
  try:
    _ = iter(iterable)
  except TypeError:
    raise TypeError('\'{}\' object is not iterable'.format(
        type(iterable).__name__))

  low = 0
  high = len(iterable) - 1
  while low < high:
    iterable[low], iterable[high] = iterable[high], iterable[low]
    low += 1
    high -= 1
