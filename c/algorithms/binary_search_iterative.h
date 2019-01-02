#ifndef BINARY_SEARCH_ITERATIVE_H
#define BINARY_SEARCH_ITERATIVE_H

// Returns the index of the element in the sorted array.
//
// Binary search works on sorted, iterable collections. Binary search begins by
// comparing the middle item in the collection with the target item. If the
// target item is equal to the middle item, its position in the array is
// returned. If the target item is less than the middle item, the search
// continues in the lower half of the collection. If the target item is greater
// than the middle item, the search continues in the upper half of the array. By
// doing this, the algorithm eliminates half of the items as a possible match
// each iteration.
//
// * O(log n) time complexity
// * O(1) space complexity
//
// Args:
//   array: An array of integers.
//   length: The length of array.
//   element: An integer to search for.
// Returns:
//   The index of the element in the sorted array, or -1 if not found.
int binary_search_iterative(const int array[], int length, int element);

#endif  // BINARY_SEARCH_ITERATIVE_H
