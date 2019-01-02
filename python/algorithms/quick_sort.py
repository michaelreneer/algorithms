#!/usr/bin/env python


def quick_sort(iterable):
  """Sorts the iterable.

  Quicksort sort is a divide and conquer, comparison sorting algorithm.
  Conceptually, the steps are:
  * Select a pivot from the collection.
  * Partition the collection so that all the items less than the pivot come
    before the pivot and all the items greater than the pivot come after the
    pivot.
  * Repeatedly apply these steps to the collection of smaller items and the
    collection of larger items until the size of the collections are either zero
    or one, which are sorted by definition.

  The pivot selection and partitioning logic can be implemented in several
  different ways and greatly affect performance. This implementation uses
  Hoare's original partition scheme and the middle index as a pivot.

  * O(n log n) time complexity
  * O(log n) space complexity
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

  def _partition(iterable, low, high):
    middle = int(low + (high - low) / 2)
    pivot = iterable[middle]
    i = low - 1
    j = high + 1
    while True:
      i += 1
      while iterable[i] < pivot:
        i += 1
      j -= 1
      while iterable[j] > pivot:
        j -= 1
      if i >= j:
        return j
      iterable[i], iterable[j] = iterable[j], iterable[i]

  def _quick_sort(iterable, low, high):
    if low >= high:
      return
    index = _partition(iterable, low, high)
    _quick_sort(iterable, low, index)
    _quick_sort(iterable, index + 1, high)

  _quick_sort(iterable, 0, len(iterable) - 1)
