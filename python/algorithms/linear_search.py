#!/usr/bin/env python


def linear_search(iterable, item):
  """Returns the index of the item in the unsorted iterable.

  Iterates through a collection, comparing each item to the target item, and
  returns the index of the first item that is equal to the target item.

  * O(n) time complexity
  * O(1) space complexity

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

  for index, _item in enumerate(iterable):
    if _item == item:
      return index
  return -1
