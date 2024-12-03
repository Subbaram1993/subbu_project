#include <stdio.h>

// Declare all your test functions
int test_bitwise_operations();
int test_manage();
int test_find_maximum();
int test_number_to_words();
int test_selection_sort();
int test_sum_of_unique_elements();

int main() {
    int test_result;

    // Run test_bitwise_operations
    test_result = test_bitwise_operations();
    printf("test_bitwise_operations: %s\n", test_result ? "PASSED" : "FAILED");

    // Run test_manage
    test_result = test_manage();
    printf("test_manage: %s\n", test_result ? "PASSED" : "FAILED");

    // Run test_find_maximum
    test_result = test_find_maximum();
    printf("test_find_maximum: %s\n", test_result ? "PASSED" : "FAILED");

    // Run test_number_to_words
    test_result = test_number_to_words();
    printf("test_number_to_words: %s\n", test_result ? "PASSED" : "FAILED");

    // Run test_selection_sort
    test_result = test_selection_sort();
    printf("test_selection_sort: %s\n", test_result ? "PASSED" : "FAILED");

    // Run test_sum_of_unique_elements
    test_result = test_sum_of_unique_elements();
    printf("test_sum_of_unique_elements: %s\n", test_result ? "PASSED" : "FAILED");

    return 0;
}
