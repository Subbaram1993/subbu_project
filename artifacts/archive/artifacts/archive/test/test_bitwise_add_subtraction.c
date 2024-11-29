#include <stdio.h>
#include <assert.h>

// Declare the functions implemented in the program
int bitwise_add(int a, int b);
int bitwise_subtract(int a, int b);

void test_bitwise_operations() {
    // Test addition
    assert(bitwise_add(3, 5) == 8);
    assert(bitwise_add(-3, 5) == 2);
    assert(bitwise_add(0, 0) == 0);

    // Test subtraction
    assert(bitwise_subtract(5, 3) == 2);
    assert(bitwise_subtract(3, 5) == -2);
    assert(bitwise_subtract(0, 0) == 0);
}

int main() {
    test_bitwise_operations();
    printf("All tests passed for bitwise_add_subtraction_operators.c\n");
    return 0;
}
