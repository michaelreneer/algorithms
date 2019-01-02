#!/usr/bin/env python


def insertion_sort(iterable):
  """Sorts the iterable.

  Insertion sort is a simple, comparison sorting algorithm that iterates through
  a collection, removes the first item from the unsorted part of the collection,
  and inserts the item into the sorted part of the collection. Iterations
  through the collection decrease the size of the unsorted part of the
  collection and are repeated until there are no items remaining.

  * O(n^2) time complexity
  * O(1) space complexity
  * stable
  * adaptive: O(n) time complexity when nearly sorted

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

  for i in range(1, len(iterable)):
    temp = iterable[i]
    j = i
    while j > 0 and iterable[j - 1] > temp:
      iterable[j] = iterable[j - 1]
      j -= 1
    iterable[j] = temp
