#!/usr/bin/env python

from __future__ import absolute_import

import unittest

import algorithms


class TestFibonacciIterative(unittest.TestCase):

  def test_fibonacci_iterative_with_zero(self):
    number = 0
    result = algorithms.fibonacci_iterative(number)
    self.assertEqual(result, 0)

  def test_fibonacci_iterative_with_one(self):
    number = 1
    result = algorithms.fibonacci_iterative(number)
    self.assertEqual(result, 1)

  def test_fibonacci_iterative_with_two(self):
    number = 2
    result = algorithms.fibonacci_iterative(number)
    self.assertEqual(result, 1)

  def test_fibonacci_iterative_with_three(self):
    number = 3
    result = algorithms.fibonacci_iterative(number)
    self.assertEqual(result, 2)

  def test_fibonacci_iterative_with_four(self):
    number = 4
    result = algorithms.fibonacci_iterative(number)
    self.assertEqual(result, 3)

  def test_fibonacci_iterative_with_five(self):
    number = 5
    result = algorithms.fibonacci_iterative(number)
    self.assertEqual(result, 5)

  def test_fibonacci_iterative_with_twenty(self):
    number = 20
    result = algorithms.fibonacci_iterative(number)
    self.assertEqual(result, 6765)

  def test_fibonacci_iterative_with_none_raises_type_error(self):
    number = None
    with self.assertRaises(TypeError):
      _ = algorithms.fibonacci_iterative(number)


if __name__ == '__main__':
  unittest.main()
