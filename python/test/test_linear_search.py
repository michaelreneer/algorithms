#!/usr/bin/env python

from __future__ import absolute_import

import unittest

import algorithms


class TestLinearIterative(unittest.TestCase):

  def test_linear_search_returns_first_index(self):
    iterable = [1, 2, 3]
    item = 1
    index = algorithms.linear_search(iterable, item)
    self.assertEqual(index, 0)

  def test_linear_search_returns_middle_index(self):
    iterable = [1, 2, 3]
    item = 2
    index = algorithms.linear_search(iterable, item)
    self.assertEqual(index, 1)

  def test_linear_search_returns_last_index(self):
    iterable = [1, 2, 3]
    item = 3
    index = algorithms.linear_search(iterable, item)
    self.assertEqual(index, 2)

  def test_linear_search_returns_no_index(self):
    iterable = [1, 2, 3]
    item = 10
    index = algorithms.linear_search(iterable, item)
    self.assertEqual(index, -1)

  def test_linear_search_with_one_item_returns_index(self):
    iterable = [1]
    item = 1
    index = algorithms.linear_search(iterable, item)
    self.assertEqual(index, 0)

  def test_linear_search_with_no_items_returns_no_index(self):
    iterable = []
    item = 1
    index = algorithms.linear_search(iterable, item)
    self.assertEqual(index, -1)

  def test_linear_search_with_string_returns_index(self):
    iterable = 'abcdefghij'
    item = 'a'
    index = algorithms.linear_search(iterable, item)
    self.assertEqual(index, 0)

  def test_linear_search_with_none_iterable_raises_type_error(self):
    iterable = None
    item = 1
    with self.assertRaises(TypeError):
      _ = algorithms.linear_search(iterable, item)

  def test_linear_search_with_none_item_returns_no_index(self):
    iterable = [1, 2, 3]
    item = None
    index = algorithms.linear_search(iterable, item)
    self.assertEqual(index, -1)


if __name__ == '__main__':
  unittest.main()
