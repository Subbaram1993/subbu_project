#include <stdio.h>
#include <assert.h>

// Declare the function implemented in the program
int find_maximum(int arr[], int size);

void test_find_maximum() {
    int arr1[] = {1, 2, 3, 4, 5};
    assert(find_maximum(arr1, 5) == 5);

    int arr2[] = {-1, -3, -5, -2};
    assert(find_maximum(arr2, 4) == -1);

    int arr3[] = {10};
    assert(find_maximum(arr3, 1) == 10);
}

int main() {
    test_find_maximum();
    printf("All tests passed for maximum_element_in_Array.c\n");
    return 0;
}
