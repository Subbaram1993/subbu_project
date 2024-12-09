#include <stdio.h>

// Declare the functions implemented in the program
int bitwiseadd(int a, int b);
int subtraction(int a, int b);

int test_bitwise_operations() {
    // Test addition
    if (bitwiseadd(3, 5) != 8) return 0;
    if (bitwiseadd(-3, 5) != 2) return 0;
    if (bitwiseadd(0, 0) != 0) return 0;

    // Test subtraction
    if (subtraction(5, 3) != 2) return 0;
    if (subtraction(3, 5) != -2) return 0;
    if (subtraction(0, 0) != 0) return 0;

    return 1; // Success
}
