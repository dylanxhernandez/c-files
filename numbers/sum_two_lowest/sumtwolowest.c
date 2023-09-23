/*

This example is a function that returns the sum of the two lowest positive numbers given an array of minimum 4 positive integers. 
- No floats or non-positive integers will be passed.

*/

#include <stddef.h>
#include <limits.h>

long sum_two_smallest_numbers(size_t n, const int numbers[n]) {
    long smallest1 = LONG_MAX; // Initialize with a very large value
    long smallest2 = LONG_MAX;

    for (size_t i = 0; i < n; i++) {
        if (numbers[i] < smallest1) {
            smallest2 = smallest1; // Update the second smallest
            smallest1 = numbers[i]; // Update the smallest
        } else if (numbers[i] < smallest2) {
            smallest2 = numbers[i]; // Update the second smallest
        }
    }

    return smallest1 + smallest2;
}
