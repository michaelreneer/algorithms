#!/usr/bin/env python


def bubble_sort(iterable):
  """Sorts the iterable.

  Bubble sort is a simple, comparison sorting algorithm that iterates through a
  collection, compares adjacent items, and swaps them if they are in the wrong
  order. Iterations through the collection are repeated until no swaps are
  needed.

  * O(n^2) time complexity
  * O(1) space complexity
  * stable
  * adaptive: O(n) when nearly sorted

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

  length = len(iterable)
  unsorted = True
  j = 1
  while unsorted:
    unsorted = False
    for i in range(length - j):
      if iterable[i] > iterable[i + 1]:
        iterable[i], iterable[i + 1] = iterable[i + 1], iterable[i]
        unsorted = True
    j += 1
