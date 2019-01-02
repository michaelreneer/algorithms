#!/usr/bin/env python

from __future__ import absolute_import

import unittest

import algorithms


class TestReverse(unittest.TestCase):

  def test_reverse_with_one_item(self):
    iterable = [1]
    algorithms.reverse(iterable)
    expected = [1]
    self.assertEqual(iterable, expected)

  def test_reverse_with_two_items(self):
    iterable = [1, 2]
    algorithms.reverse(iterable)
    expected = [2, 1]
    self.assertEqual(iterable, expected)

  def test_reverse_with_three_items(self):
    iterable = [1, 2, 3]
    algorithms.reverse(iterable)
    expected = [3, 2, 1]
    self.assertEqual(iterable, expected)

  def test_reverse_with_ten_items(self):
    iterable = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    algorithms.reverse(iterable)
    expected = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    self.assertEqual(iterable, expected)

  def test_reverse_with_equal_items(self):
    iterable = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    algorithms.reverse(iterable)
    expected = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    self.assertEqual(iterable, expected)

  def test_reverse_with_strings(self):
    iterable = ['a', 's', 'd', 'f']
    algorithms.reverse(iterable)
    expected = ['f', 'd', 's', 'a']
    self.assertEqual(iterable, expected)

  def test_reverse_with_no_items(self):
    iterable = []
    algorithms.reverse(iterable)
    expected = []
    self.assertEqual(iterable, expected)

  def test_reverse_with_none_raises_type_error(self):
    iterable = None
    with self.assertRaises(TypeError):
      algorithms.reverse(iterable)


if __name__ == '__main__':
  unittest.main()
