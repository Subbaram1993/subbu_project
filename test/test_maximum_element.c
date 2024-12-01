#include <stdio.h>

// Declare the function implemented in the program
int find_maximum(int arr[], int size);

int test_find_maximum() {
    int arr1[] = {1, 2, 3, 4, 5};
    if (find_maximum(arr1, 5) != 5) return 0;

    int arr2[] = {-1, -3, -5, -2};
    if (find_maximum(arr2, 4) != -1) return 0;

    int arr3[] = {10};
    if (find_maximum(arr3, 1) != 10) return 0;

    return 1; // Success
}
