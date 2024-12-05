#include <stdio.h>
#include <string.h>

// Declare the function implemented in the program
const char* print_to_letters(int num);

int test_number_to_words() {
    // Test for various numbers
    if (strcmp(print_to_letters(123), "one hundred twenty-three") != 0) {
        printf("Test failed: Expected 'one hundred twenty-three', got '%s'\n", print_to_letters(123));
        return 0;
    }
    if (strcmp(print_to_letters(0), "zero") != 0) {
        printf("Test failed: Expected 'zero', got '%s'\n", print_to_letters(0));
        return 0;
    }
    if (strcmp(print_to_letters(-45), "negative forty-five") != 0) {
        printf("Test failed: Expected 'negative forty-five', got '%s'\n", print_to_letters(-45));
        return 0;
    }

    return 1; // Success if all tests pass
}