#!/usr/bin/env python

from __future__ import absolute_import

import unittest

import algorithms


class TestQuickSort(unittest.TestCase):

  def test_quick_sort_with_one_item(self):
    iterable = [1]
    algorithms.quick_sort(iterable)
    expected = [1]
    self.assertEqual(iterable, expected)

  def test_quick_sort_with_two_items_1(self):
    iterable = [1, 2]
    algorithms.quick_sort(iterable)
    expected = [1, 2]
    self.assertEqual(iterable, expected)

  def test_quick_sort_with_two_items_2(self):
    iterable = [2, 1]
    algorithms.quick_sort(iterable)
    expected = [1, 2]
    self.assertEqual(iterable, expected)

  def test_quick_sort_with_three_items_1(self):
    iterable = [1, 2, 3]
    algorithms.quick_sort(iterable)
    expected = [1, 2, 3]
    self.assertEqual(iterable, expected)

  def test_quick_sort_with_three_items_2(self):
    iterable = [1, 3, 2]
    algorithms.quick_sort(iterable)
    expected = [1, 2, 3]
    self.assertEqual(iterable, expected)

  def test_quick_sort_with_three_items_3(self):
    iterable = [2, 1, 3]
    algorithms.quick_sort(iterable)
    expected = [1, 2, 3]
    self.assertEqual(iterable, expected)

  def test_quick_sort_with_three_items_4(self):
    iterable = [2, 3, 1]
    algorithms.quick_sort(iterable)
    expected = [1, 2, 3]
    self.assertEqual(iterable, expected)

  def test_quick_sort_with_three_items_5(self):
    iterable = [3, 1, 2]
    algorithms.quick_sort(iterable)
    expected = [1, 2, 3]
    self.assertEqual(iterable, expected)

  def test_quick_sort_with_three_items_6(self):
    iterable = [3, 2, 1]
    algorithms.quick_sort(iterable)
    expected = [1, 2, 3]
    self.assertEqual(iterable, expected)

  def test_quick_sort_with_ascending_items(self):
    iterable = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    algorithms.quick_sort(iterable)
    expected = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    self.assertEqual(iterable, expected)

  def test_quick_sort_with_descending_items(self):
    iterable = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    algorithms.quick_sort(iterable)
    expected = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    self.assertEqual(iterable, expected)

  def test_quick_sort_with_equal_items(self):
    iterable = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    algorithms.quick_sort(iterable)
    expected = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    self.assertEqual(iterable, expected)

  def test_quick_sort_with_strings(self):
    iterable = ['a', 's', 'd', 'f']
    algorithms.quick_sort(iterable)
    expected = ['a', 'd', 'f', 's']
    self.assertEqual(iterable, expected)

  def test_quick_sort_with_no_items(self):
    iterable = []
    algorithms.quick_sort(iterable)
    expected = []
    self.assertEqual(iterable, expected)

  def test_quick_sort_with_none_iterable_raises_type_error(self):
    iterable = None
    with self.assertRaises(TypeError):
      algorithms.quick_sort(iterable)

  def test_quick_sort_is_not_stable(self):
    iterable = [[1], [1], [1], [1]]
    ids = [id(item) for item in iterable]
    algorithms.quick_sort(iterable)
    expected = [id(item) for item in iterable]
    self.assertNotEqual(ids, expected)


if __name__ == '__main__':
  unittest.main()
