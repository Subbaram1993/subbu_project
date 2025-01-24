#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int *a, int n);
int binary_search(int *a, int n, int target);

int test_bubble_sort_and_binary_search() {
    int arr1[] = {5, 3, 4, 1, 2};
    int sorted1[] = {1, 2, 3, 4, 5};
    bubble_sort(arr1, 5);
    for (int i = 0; i < 5; i++) {
        if (arr1[i] != sorted1[i]) return 0;
    }

    int arr2[] = {10, 5, 0, -1};
    int sorted2[] = {-1, 0, 5, 10};
    bubble_sort(arr2, 4);
    for (int i = 0; i < 4; i++) {
        if (arr2[i] != sorted2[i]) return 0;
    }

    int arr3[] = {1, 2, 3, 4, 5};
    if (binary_search(arr3, 5, 3) != 2) return 0;
    if (binary_search(arr3, 5, 6) != -1) return 0;

    int arr4[] = {-1, 0, 5, 10};
    if (binary_search(arr4, 4, 0) != 1) return 0;
    if (binary_search(arr4, 4, -2) != -1) return 0;

    return 1;
}
