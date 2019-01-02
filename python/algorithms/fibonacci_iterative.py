#!/usr/bin/env python


def fibonacci_iterative(number):
  """Returns the nth Fibonacci number in the Fibonacci sequence.

  The Fibonacci numbers are the numbers in the Fibonacci sequence, defined by
  the equation and seed values:

  F(n) = F(n - 1) + F(n - 2)

  F(0) = 0
  F(1) = 1

  * O(n) time complexity
  * O(1) space complexity

  Args:
    number: An integer.
  """
  if number == 0 or number == 1:
    return number
  a = 0
  b = 1
  for _ in range(2, number + 1):
    a, b = b, a + b
  return b
