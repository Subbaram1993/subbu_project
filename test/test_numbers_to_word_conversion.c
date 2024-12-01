#include <stdio.h>
#include <string.h>

// Declare the function implemented in the program
const char* number_to_words(int num);

int test_number_to_words() {
    if (strcmp(number_to_words(123), "one hundred twenty-three") != 0) return 0;
    if (strcmp(number_to_words(0), "zero") != 0) return 0;
    if (strcmp(number_to_words(-45), "negative forty-five") != 0) return 0;

    return 1; // Success
}
