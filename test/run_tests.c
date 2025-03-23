#include <stdio.h>

// Declare existing test functions
int test_manage();
int test_bitwise_operations();
int test_find_maximum();
int test_number_to_words();
int test_selection_sort();
int test_sum_of_unique_elements();
int test_bubble_sort_and_binary_search();

// Single entry point for student information tests
int test_student_operations();

int main() {
    int test_result;
    int overall_result = 1; // Assume all tests pass initially

    // Run test_manage
    test_result = test_manage();
    printf("test_manage: %s\n", test_result ? "PASSED" : "FAILED");
    if (!test_result) overall_result = 0;

    // Run test_bitwise_operations
    test_result = test_bitwise_operations();
    printf("test_bitwise_operations: %s\n", test_result ? "PASSED" : "FAILED");
    if (!test_result) overall_result = 0;

    // Run test_find_maximum
    test_result = test_find_maximum();
    printf("test_find_maximum: %s\n", test_result ? "PASSED" : "FAILED");
    if (!test_result) overall_result = 0;

    // Run test_number_to_words
    test_result = test_number_to_words();
    printf("test_number_to_words: %s\n", test_result ? "PASSED" : "FAILED");
    if (!test_result) overall_result = 0;

    // Run test_selection_sort
    test_result = test_selection_sort();
    printf("test_selection_sort: %s\n", test_result ? "PASSED" : "FAILED");
    if (!test_result) overall_result = 0;

    // Run test_sum_of_unique_elements
    test_result = test_sum_of_unique_elements();
    printf("test_sum_of_unique_elements: %s\n", test_result ? "PASSED" : "FAILED");
    if (!test_result) overall_result = 0;

    // Run test_bubble_sort_and_binary_search
    test_result = test_bubble_sort_and_binary_search();
    printf("test_bubble_sort_and_binary_search: %s\n", test_result ? "PASSED" : "FAILED");
    if (!test_result) overall_result = 0;

    // Run student information tests (single function to call all internally)
    test_result = test_student_operations();
    printf("test_student_operations: %s\n", test_result ? "PASSED" : "FAILED");
    if (!test_result) overall_result = 0;

    // Run student information tests
    test_result = test_student_operations();
    printf("test_student_operations: %s\n", test_result ? "PASSED" : "FAILED");
    if (!test_result) overall_result = 0;
    
    // Return 0 for success, 1 for failure
    return overall_result ? 0 : 1;
}
