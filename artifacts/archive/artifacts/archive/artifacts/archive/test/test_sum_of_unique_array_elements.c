#include <stdio.h>
#include <assert.h>

// Declare the function implemented in the program
int sum_of_unique_elements(int arr[], int size);

void test_sum_of_unique_elements() {
    int arr1[] = {1, 2, 2, 3, 4, 4};
    assert(sum_of_unique_elements(arr1, 6) == 4); // 1 + 3 = 4

    int arr2[] = {1, 1, 1, 1};
    assert(sum_of_unique_elements(arr2, 4) == 0); // No unique elements

    int arr3[] = {5};
    assert(sum_of_unique_elements(arr3, 1) == 5); // Single unique element
}

int main() {
    test_sum_of_unique_elements();
    printf("All tests passed for sum_of_unique_array_elements.c\n");
    return 0;
}
