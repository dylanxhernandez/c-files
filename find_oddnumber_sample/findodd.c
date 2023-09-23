/*

This sample was used to solve a sample scenario:
- Given an array of integers, find the one that appears an odd number of times.

*/
#include <stddef.h>

int find_odd(size_t length, const int array[length]) {
    int result = 0;
    for (size_t i = 0; i < length; i++) {
        result ^= array[i];
    }
    return result;
}

