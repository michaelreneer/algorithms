#!/usr/bin/env python

from __future__ import absolute_import

import sys
import unittest

import algorithms


class TestBinarySearchIterative(unittest.TestCase):

  def test_binary_search_iterative_returns_first_index(self):
    iterable = [1, 2, 3]
    item = 1
    index = algorithms.binary_search_iterative(iterable, item)
    self.assertEqual(index, 0)

  def test_binary_search_iterative_returns_middle_index(self):
    iterable = [1, 2, 3]
    item = 2
    index = algorithms.binary_search_iterative(iterable, item)
    self.assertEqual(index, 1)

  def test_binary_search_iterative_returns_last_index(self):
    iterable = [1, 2, 3]
    item = 3
    index = algorithms.binary_search_iterative(iterable, item)
    self.assertEqual(index, 2)

  def test_binary_search_iterative_returns_no_index(self):
    iterable = [1, 2, 3]
    item = 10
    index = algorithms.binary_search_iterative(iterable, item)
    self.assertEqual(index, -1)

  def test_binary_search_iterative_with_one_item_returns_index(self):
    iterable = [1]
    item = 1
    index = algorithms.binary_search_iterative(iterable, item)
    self.assertEqual(index, 0)

  def test_binary_search_iterative_with_no_items_returns_no_index(self):
    iterable = []
    item = 1
    index = algorithms.binary_search_iterative(iterable, item)
    self.assertEqual(index, -1)

  def test_binary_search_iterative_with_string_returns_index(self):
    iterable = 'abcdefghij'
    item = 'a'
    index = algorithms.binary_search_iterative(iterable, item)
    self.assertEqual(index, 0)

  def test_binary_search_iterative_with_none_iterable_raises_type_error(self):
    iterable = None
    item = 1
    with self.assertRaises(TypeError):
      _ = algorithms.binary_search_iterative(iterable, item)

  def test_binary_search_iterative_with_none_item_raises_type_error(self):
    iterable = [1, 2, 3]
    item = None
    # Comparisons between 'int' and 'NoneType' should raise a 'TypeError'.
    if sys.version_info > (3, 0):
      with self.assertRaises(TypeError):
        _ = algorithms.binary_search_iterative(iterable, item)
    else:
      index = algorithms.binary_search_iterative(iterable, item)
      self.assertEqual(index, -1)


if __name__ == '__main__':
  unittest.main()
