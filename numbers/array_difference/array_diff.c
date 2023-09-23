/*

This function demonstrates a simple array difference function in C. 

This code subtracts one list from another and returns the result while removing all values from list arr1 that are present in arr2, you can follow these steps:

    - Initialize an array result with the same size as arr1 to store the elements that are not present in arr2.
    - Iterate through arr1 and check whether each element is present in arr2. If an element is not present, add it to the result array.
    - Keep track of the length of the result array.
    - Return the result array and assign its length to the z pointer.

*/

#include <stdlib.h>

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z) {
    // Initialize the result array with the same size as arr1
    int *result = (int *)malloc(n1 * sizeof(int));
    if (result == NULL) {
        // Handle memory allocation failure
        *z = 0;
        return NULL;
    }

    size_t result_length = 0;  // Length of the result array

    for (size_t i = 0; i < n1; i++) {
        int element = arr1[i];
        int found = 0;

        // Check if the element is present in arr2
        for (size_t j = 0; j < n2; j++) {
            if (element == arr2[j]) {
                found = 1;
                break;
            }
        }

        // If the element is not present in arr2, add it to the result array
        if (!found) {
            result[result_length] = element;
            result_length++;
        }
    }

    // Resize the result array to the actual length
    result = (int *)realloc(result, result_length * sizeof(int));

    // Assign the length of the result array to the z pointer
    *z = result_length;

    return result;
}
