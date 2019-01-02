#!/usr/bin/env python


def binary_search_recursive(iterable, item):
  """Returns the index of the item in the sorted iterable.

  Binary search works on sorted, iterable collections. Binary search begins by
  comparing the middle item in the collection with the target item. If the
  target item is equal to the middle item, its position in the array is
  returned. If the target item is less than the middle item, the search
  continues in the lower half of the collection. If the target item is greater
  than the middle item, the search continues in the upper half of the array. By
  doing this, the algorithm eliminates half of the items as a possible match
  each iteration.

  * O(log n) time complexity
  * O(log n) space complexity

  Args:
    iterable: A collection that is iterable.
    item: An object to search for.
  Returns:
    The index of the item in the sorted iterable, or -1 if not found.
  Raises:
    TypeError: If iterable is not iterable.
  """
  try:
    _ = iter(iterable)
  except TypeError:
    raise TypeError('\'{}\' object is not iterable'.format(
        type(iterable).__name__))

  def _binary_search_recursive(iterable, item, low, high):
    if low > high:
      return -1
    middle = int(low + (high - low) / 2)
    if iterable[middle] < item:
      return _binary_search_recursive(iterable, item, middle + 1, high)
    elif iterable[middle] > item:
      return _binary_search_recursive(iterable, item, low, middle - 1)
    return middle

  return _binary_search_recursive(iterable, item, 0, len(iterable) - 1)
