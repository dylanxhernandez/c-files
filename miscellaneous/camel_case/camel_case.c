#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
    This function converts a string to camelCase, that is, all words must have their first letter capitalized and spaces must be removed.
*/

char *camel_case(const char *s)
{
    if (s == NULL || *s == '\0') {
        // Handle empty or NULL input by returning an empty string
        char *emptyString = (char *)malloc(1);
        if (emptyString == NULL) {
            // Memory allocation failed
            return NULL;
        }
        emptyString[0] = '\0';
        return emptyString;
    }

    char *result = (char *)malloc(strlen(s) + 1);
    if (result == NULL) {
        // Memory allocation failed
        return NULL;
    }

    int i, j = 0;
    int capitalize = 1; // Start with capitalizing the first character

    for (i = 0; s[i] != '\0'; i++) {
        if (isspace(s[i])) {
            // Skip spaces
            capitalize = 1;
        } else if (isalnum(s[i])) {
            // Check if it's an alphanumeric character
            if (capitalize) {
                result[j] = toupper(s[i]); // Capitalize the character
                capitalize = 0;
            } else {
                result[j] = tolower(s[i]);
            }
            j++;
        }
    }

    result[j] = '\0'; // Null-terminate the result string
    return result;
}

int main() {
    const char *input1 = "hello case";
    char *output1 = camel_case(input1);
    printf("%s --> %s\n", input1, output1);
    free(output1); // Remember to free the allocated memory

    const char *input2 = "camel case word";
    char *output2 = camel_case(input2);
    printf("%s --> %s\n", input2, output2);
    free(output2); // Remember to free the allocated memory

    const char *input3 = ""; // Empty string
    char *output3 = camel_case(input3);
    printf("%s --> %s\n", input3, output3);
    free(output3); // Remember to free the allocated memory

    const char *input4 = NULL; // NULL input
    char *output4 = camel_case(input4);
    printf("%s --> %s\n", input4, output4);
    free(output4); // Remember to free the allocated memory

    return 0;
}

