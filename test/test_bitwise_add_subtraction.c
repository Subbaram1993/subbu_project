#include <stdio.h>

// Declare the functions implemented in the program
int bitwise_add(int a, int b);
int bitwise_subtract(int a, int b);

int test_bitwise_operations() {
    // Test addition
    if (bitwise_add(3, 5) != 8) return 0;
    if (bitwise_add(-3, 5) != 2) return 0;
    if (bitwise_add(0, 0) != 0) return 0;

    // Test subtraction
    if (bitwise_subtract(5, 3) != 2) return 0;
    if (bitwise_subtract(3, 5) != -2) return 0;
    if (bitwise_subtract(0, 0) != 0) return 0;

    return 1; // Success
}
