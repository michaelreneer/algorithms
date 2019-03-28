#!/usr/bin/env python


def merge_sort_natural(iterable):
  """Sorts the iterable.

  Merge sort is a divide and conquer, comparison sorting algorithm.
  Conceptually, the steps are:
  * Divide the collection into n smaller collections, each containing one item,
    which are sorted by definition.
  * Repeatedly merge the smaller collections into larger sorted collections
    until there is only one sorted collection remaining.

  * O(n log n) time complexity
  * O(n) space complexity
  * not stable
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

  def _merge(src, dest, low, high, ascending):
    # Copy the next largest element from src to dest.
    i = low if ascending else high
    j = low
    k = high
    while j <= k:
      if src[j] <= src[k]:
        dest[i] = src[j]
        j += 1
      else:
        dest[i] = src[k]
        k -= 1
      if ascending:
        i += 1
      else:
        i -= 1

  def _merge_runs(src, dest, length):
    ascending = True
    i = 0
    j = 0
    while i < length:
      j = i
      item = src[i]
      i += 1
      while i < length and item <= src[i]:
        item = src[i]
        i += 1
      while i < length and item >= src[i]:
        item = src[i]
        i += 1
      _merge(src, dest, j, i - 1, ascending)
      ascending = not ascending
    return j == 0

  def _merge_sort_natural(iterable, temp, length):
    unsorted = True
    while unsorted:
      _merge_runs(iterable, temp, length)
      unsorted = not _merge_runs(temp, iterable, length)

  length = len(iterable)
  temp = [None] * length
  _merge_sort_natural(iterable, temp, length)
