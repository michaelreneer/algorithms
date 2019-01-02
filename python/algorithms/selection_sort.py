#!/usr/bin/env python


def selection_sort(iterable):
  """Sorts the iterable.

  Selection sort is a simple, comparison sorting algorithm that iterates through
  a collection, finds the smallest (or largest) item from the unsorted part of
  the collection, and appends the item to the end of the sorted part of the
  collection. Iterations through the collection decrease the size of the
  unsorted part of the collection and are repeated until there are no items
  remaining.

  * O(n^2) time complexity
  * O(1) space complexity
  * not stable
  * not adaptive

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
  for i in range(0, length):
    low = i
    for j in range(i + 1, length):
      if iterable[j] < iterable[low]:
        low = j
    if i != low:
      iterable[i], iterable[low] = iterable[low], iterable[i]
