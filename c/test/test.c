#include "test.h"

#include "testc.h"

int main(void) {
  // Sorting
  test_bubble_sort();
  test_insertion_sort();
  test_merge_sort_bottom_up();
  test_merge_sort_natural();
  test_merge_sort_top_down();
  test_quick_sort();
  test_selection_sort();

  // Search
  test_binary_search_iterative();
  test_binary_search_recursive();
  test_linear_search();

  // Bit
  test_count_set_bits();

  // Collection
  test_reverse();

  // Math
  test_fibonacci_iterative();
  test_fibonacci_recursive();

  test_results();

  return 0;
}
