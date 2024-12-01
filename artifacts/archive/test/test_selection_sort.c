#include <stdio.h>
#include <assert.h>

// Declare the function implemented in the program
void selection_sort(int arr[], int size);

void test_selection_sort() {
    int arr1[] = {5, 3, 4, 1, 2};
    int sorted1[] = {1, 2, 3, 4, 5};
    selection_sort(arr1, 5);
    for (int i = 0; i < 5; i++) {
        assert(arr1[i] == sorted1[i]);
    }

    int arr2[] = {10, 5, 0, -1};
    int sorted2[] = {-1, 0, 5, 10};
    selection_sort(arr2, 4);
    for (int i = 0; i < 4; i++) {
        assert(arr2[i] == sorted2[i]);
    }
}

int main() {
    test_selection_sort();
    printf("All tests passed for selection_sort.c\n");
    return 0;
}
