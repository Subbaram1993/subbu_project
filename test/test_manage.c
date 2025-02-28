#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // Required for getcwd()

// Function declarations
extern void print_list(FILE *fp1); // Assuming the function is defined elsewhere

// Function to compare the expected and actual output
int compare_output(const char *expected_output, const char *actual_output) {
    return strcmp(expected_output, actual_output) == 0;
}

// Mock function to simulate file creation for testing
void create_test_file() {
    // Ensure the directory exists
    system("mkdir -p ../Output_Files");

    // Check current working directory for debugging
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    }

    // Open the file for writing in the correct directory
    FILE *fp = fopen("../Output_Files/cheeti.txt", "w");
    if (fp == NULL) {
        printf("Unable to open file for test.\n");
        exit(1);
    }

    // Write some test data into the file
    fprintf(fp, "January\t: 1000\nFebruary\t: 1200\n");
    fprintf(fp, "Total :2200.00");
    fclose(fp);
}

// Updated test function
int test_manage() {
    // Create a file with known content for testing
    create_test_file();

    // Redirect stdout to a temporary file to capture print_list output
    FILE *output_file = fopen("test_output.txt", "w");
    if (output_file == NULL) {
        printf("Failed to open the output file.\n");
        return 0; // Fail the test if the file cannot be opened
    }

    int stdout_fd = dup(fileno(stdout)); // Save original stdout
    freopen("test_output.txt", "w", stdout);  // Redirect stdout to a file

    // Open the input file for printing
    FILE *fp = fopen("../Output_Files/cheeti.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file for reading.\n");
        fclose(output_file);
        return 0; // Fail the test if the file cannot be opened
    }

    // Call the function to test it
    print_list(fp);
    fclose(fp); // Close the file pointer after the test

    // Restore stdout to the console
    fflush(stdout);
    dup2(stdout_fd, fileno(stdout)); // Restore stdout
    close(stdout_fd);
    fclose(output_file); // Close the output file properly

    // Read the content of the output file
    FILE *result_file = fopen("test_output.txt", "r");
    if (result_file == NULL) {
        printf("Failed to read the output file.\n");
        return 0; // Fail the test if the output file cannot be opened
    }

    // Read the actual output into a string
    char actual_output[1024];
    size_t n = fread(actual_output, sizeof(char), sizeof(actual_output) - 1, result_file);
    actual_output[n] = '\0';  // Null-terminate the string
    fclose(result_file); // Properly close the result file

    // Define the expected output
    const char *expected_output = "January\t: 1000\nFebruary\t: 1200\nTotal :2200.00";

    // Compare the actual and expected output
    return compare_output(expected_output, actual_output) ? 1 : 0;
}