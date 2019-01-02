#!/usr/bin/env python

from __future__ import absolute_import

import unittest

import algorithms


class TestCountSetBits(unittest.TestCase):

  def test_count_set_bits_with_zero(self):
    number = 0
    count = algorithms.count_set_bits(number)
    self.assertEqual(count, 0)

  def test_count_set_bits_with_one(self):
    number = 1
    count = algorithms.count_set_bits(number)
    self.assertEqual(count, 1)

  def test_count_set_bits_with_two(self):
    number = 2
    count = algorithms.count_set_bits(number)
    self.assertEqual(count, 1)

  def test_count_set_bits_with_three(self):
    number = 3
    count = algorithms.count_set_bits(number)
    self.assertEqual(count, 2)

  def test_count_set_bits_with_four(self):
    number = 4
    count = algorithms.count_set_bits(number)
    self.assertEqual(count, 1)

  def test_count_set_bits_with_five(self):
    number = 5
    count = algorithms.count_set_bits(number)
    self.assertEqual(count, 2)

  def test_count_set_bits_with_twenty(self):
    number = 20
    count = algorithms.count_set_bits(number)
    self.assertEqual(count, 2)

  def test_count_set_bits_with_none_raises_type_error(self):
    number = None
    with self.assertRaises(TypeError):
      _ = algorithms.count_set_bits(number)


if __name__ == '__main__':
  unittest.main()
