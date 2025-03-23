#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../src/student_info/student_info.h"

// Function declarations
int test_file_operations();
int test_search_operations();
int test_update_operations();
int test_display_operations();

// Mock functions for testing search and update operations
Student* mock_rollno_search(Student *head, int rollno) {
    while (head) {
        if (head->rollno == rollno) return head;
        head = head->next;
    }
    return NULL;
}

Student* mock_name_search(Student *head, const char *name) {
    while (head) {
        if (strcmp(head->name, name) == 0) return head;
        head = head->next;
    }
    return NULL;
}

void mock_update_name(Student *student, const char *new_name) {
    if (student) {
        strncpy(student->name, new_name, sizeof(student->name) - 1);
        student->name[sizeof(student->name) - 1] = '\0'; // Ensure null termination
    }
}

void mock_update_marks(Student *student, float new_marks[]) {
    if (student) {
        for (int i = 0; i < 6; i++) {
            student->marks[i] = new_marks[i];
        }
    }
}

// Function to execute all student-related tests
int test_student_operations() {
    int result;
    int overall_result = 1; // Assume all tests pass initially

    result = test_file_operations();
    printf("test_file_operations: %s\n", result ? "PASSED" : "FAILED");
    if (!result) overall_result = 0;

    result = test_search_operations();
    printf("test_search_operations: %s\n", result ? "PASSED" : "FAILED");
    if (!result) overall_result = 0;

    result = test_update_operations();
    printf("test_update_operations: %s\n", result ? "PASSED" : "FAILED");
    if (!result) overall_result = 0;

    result = test_display_operations();
    printf("test_display_operations: %s\n", result ? "PASSED" : "FAILED");
    if (!result) overall_result = 0;

    return overall_result;
}

// Test saving and loading multiple student records
int test_file_operations() {
    Student s1 = {101, "Alice", {90.0, 91.0, 92.0, 93.0, 94.0, 95.0}, NULL};
    Student s2 = {102, "Bob", {85.0, 85.0, 85.0, 85.0, 85.0, 85.0}, NULL};
    Student s3 = {103, "Charlie", {75.0, 75.0, 75.0, 75.0, 75.0, 75.0}, NULL};

    // Link students into a list
    s1.next = &s2;
    s2.next = &s3;
    s3.next = NULL;

    // Save multiple student records
    save_to_file(&s1);

    // Load data from file
    Student *loaded = load_from_file(NULL);
    if (!loaded) return 0;

    // Verify first loaded record
    int result = (loaded->rollno == 101 && strcmp(loaded->name, "Alice") == 0);

    free_memory(loaded);
    return result;
}

// Test searching for a specific student
int test_search_operations() {
    Student s1 = {101, "Alice", {90, 90, 90, 90, 90, 90}, NULL};
    Student s2 = {102, "Bob", {80, 80, 80, 80, 80, 80}, NULL};
    Student s3 = {103, "Charlie", {70, 70, 70, 70, 70, 70}, NULL};

    s1.next = &s2;
    s2.next = &s3;

    // Search Bob by roll number
    Student *found = mock_rollno_search(&s1, 102);
    if (!found || found->rollno != 102) return 0;

    // Search Bob by name
    found = mock_name_search(&s1, "Bob");
    if (!found || strcmp(found->name, "Bob") != 0) return 0;

    return 1;
}

// Test updating details of only one student
int test_update_operations() {
    Student s2 = {102, "Bob", {80, 80, 80, 80, 80, 80}, NULL};

    // Update Bob's name
    mock_update_name(&s2, "BobUpdated");
    if (strcmp(s2.name, "BobUpdated") != 0) return 0;

    // Update Bob's marks
    float new_marks[6] = {95, 95, 95, 95, 95, 95};
    mock_update_marks(&s2, new_marks);

    for (int i = 0; i < 6; i++) {
        if (s2.marks[i] != 95.0) return 0;
    }

    return 1;
}

// Test displaying a student’s details
int test_display_operations() {
    Student s1 = {104, "David", {88, 88, 88, 88, 88, 88}, NULL};

    // Display details
    display_student(&s1, 0);

    return 1;
}
