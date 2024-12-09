#include <stdio.h>

// Declare the function implemented in the program
void find_min_max(int arr[], int size, int *min, int *max);

int test_find_maximum() {
    int min, max;

    // Test 1: Check array with positive numbers
    int arr1[] = {1, 2, 3, 4, 5};
    find_min_max(arr1, 5, &min, &max);
    if (max != 5 || min != 1) {  // Check if max is 5 and min is 1
        printf("Test failed for arr1: Expected min 1, max 5, got min %d, max %d\n", min, max);
        return 0;
    }

    // Test 2: Check array with negative numbers
    int arr2[] = {-1, -3, -5, -2};
    find_min_max(arr2, 4, &min, &max);
    if (max != -1 || min != -5) {  // Check if max is -1 and min is -5
        printf("Test failed for arr2: Expected min -5, max -1, got min %d, max %d\n", min, max);
        return 0;
    }

    // Test 3: Check single element array
    int arr3[] = {10};
    find_min_max(arr3, 1, &min, &max);
    if (max != 10 || min != 10) {  // Single element array, max and min should both be 10
        printf("Test failed for arr3: Expected min 10, max 10, got min %d, max %d\n", min, max);
        return 0;
    }

    // Test 4: Check array with repeated elements
    int arr4[] = {2, 2, 2, 2};
    find_min_max(arr4, 4, &min, &max);
    if (max != 2 || min != 2) {  // Both max and min should be 2
        printf("Test failed for arr4: Expected min 2, max 2, got min %d, max %d\n", min, max);
        return 0;
    }

    return 1; // Success if all tests pass
}