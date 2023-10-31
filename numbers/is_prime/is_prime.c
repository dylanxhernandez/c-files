#include <stdbool.h>
#include <math.h>
#include <stdio.h>

/*

    This function takes an integer argument and returns a logical value true or false depending on if the integer is a prime.

    This function first handles some special cases where the number is less than or equal to 1, then it checks divisibility by 2 and 3. After that, it uses a loop to check divisibility by numbers in the form 6k ± 1 (this is an optimization to reduce the number of checks). If none of these conditions are met, the number is considered prime, and the function returns true.

    You can call this function with different integers to check whether they are prime or not.

*/

bool is_prime(int num)
{
    if (num <= 1)
    {
        return false;  // 0 and 1 are not prime numbers
    }
    else if (num <= 3)
    {
        return true;   // 2 and 3 are prime numbers
    }
    else if (num % 2 == 0 || num % 3 == 0)
    {
        return false;  // Any multiple of 2 or 3 is not prime
    }
    
    int i = 5;
    while (i * i <= num)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;  // If num is divisible by any number in the form 6k ± 1, it's not prime
        }
        i += 6;
    }
    
    return true;
}

int main() {
    int num;
    
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    if (is_prime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }
    
    return 0;
}
