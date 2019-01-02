#!/usr/bin/env python


def fibonacci_recursive(number):
  """Returns the nth Fibonacci number in the Fibonacci sequence.

  The Fibonacci numbers are the numbers in the Fibonacci sequence, defined by
  the equation and seed values:

  F(n) = F(n - 1) + F(n - 2)

  F(0) = 0
  F(1) = 1

  * O(2^n) time complexity
  * O(n) space complexity

  Args:
    number: An integer.
  """
  if number == 0 or number == 1:
    return number
  return fibonacci_recursive(number - 1) + fibonacci_recursive(number - 2)
