#include <stdio.h>

// Declare the function implemented in the program
void selection_sort(int arr[], int size);

int test_selection_sort() {
    int arr1[] = {5, 3, 4, 1, 2};
    int sorted1[] = {1, 2, 3, 4, 5};
    selection_sort(arr1, 5);
    for (int i = 0; i < 5; i++) {
        if (arr1[i] != sorted1[i]) return 0;
    }

    int arr2[] = {10, 5, 0, -1};
    int sorted2[] = {-1, 0, 5, 10};
    selection_sort(arr2, 4);
    for (int i = 0; i < 4; i++) {
        if (arr2[i] != sorted2[i]) return 0;
    }

    return 1; // Success
}
