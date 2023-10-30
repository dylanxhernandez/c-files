#include <stdio.h>

/*
    Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is produced. 
    The input will be a non-negative integer.
*/

int digital_root(int n) {
    // Base case: If the number is a single digit, return it
    if (n < 10) {
        return n;
    }

    int sum = 0;
    while (n > 0) {
        sum += n % 10;  // Add the last digit to the sum
        n /= 10;        // Remove the last digit from the number
    }

    // Recursively call digital_root with the sum
    return digital_root(sum);
}

int main() {
    int input;

    printf("Enter a non-negative integer: ");
    scanf("%d", &input);

    if (input < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        int result = digital_root(input);
        printf("The digital root of %d is %d\n", input, result);
    }

    return 0;
}
