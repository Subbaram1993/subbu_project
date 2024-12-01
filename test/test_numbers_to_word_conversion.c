#include <stdio.h>
#include <string.h>

// Declare the function implemented in the program
const char* print_to_letters(int num);

int test_number_to_words() {
    if (strcmp(print_to_letters(123), "one hundred twenty-three") != 0) return 0;
    if (strcmp(print_to_letters(0), "zero") != 0) return 0;
    if (strcmp(print_to_letters(-45), "negative forty-five") != 0) return 0;

    return 1; // Success
}
