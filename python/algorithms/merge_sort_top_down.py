#!/usr/bin/env python


def merge_sort_top_down(iterable):
  """Sorts the iterable.

  Merge sort is a divide and conquer, comparison sorting algorithm.
  Conceptually, the steps are:
  * Divide the collection into n smaller collections, each containing one item,
    which are sorted by definition.
  * Repeatedly merge the smaller collections into larger sorted collections
    until there is only one sorted collection remaining.

  * O(n log n) time complexity
  * O(n) space complexity
  * stable
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

  def _merge(iterable, temp, low, middle, high):
    for i in range(low, high + 1):
      temp[i] = iterable[i]
    i = low
    j = low
    k = middle + 1
    while j < middle + 1 and k < high + 1:
      if temp[j] <= temp[k]:
        iterable[i] = temp[j]
        j += 1
      else:
        iterable[i] = temp[k]
        k += 1
      i += 1
    while j < middle + 1:
      iterable[i] = temp[j]
      i += 1
      j += 1

  def _merge_sort_top_down(iterable, temp, low, high):
    if low >= high:
      return
    middle = int(low + (high - low) / 2)
    _merge_sort_top_down(iterable, temp, low, middle)
    _merge_sort_top_down(iterable, temp, middle + 1, high)
    _merge(iterable, temp, low, middle, high)

  length = len(iterable)
  temp = [None] * length
  _merge_sort_top_down(iterable, temp, 0, length - 1)
