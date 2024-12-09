#include <stdio.h>

// Declare the function implemented in the program
int sum_of_unique_elements(int arr[], int size);

int test_sum_of_unique_elements() {
    int arr1[] = {1, 2, 2, 3, 4, 4};
    if (sum_of_unique_elements(arr1, 6) != 4) return 0; // 1 + 3 = 4

    int arr2[] = {1, 1, 1, 1};
    if (sum_of_unique_elements(arr2, 4) != 0) return 0; // No unique elements

    int arr3[] = {5};
    if (sum_of_unique_elements(arr3, 1) != 5) return 0; // Single unique element

    return 1; // Success
}
