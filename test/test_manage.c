#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function declarations
extern void print_list(FILE *fp1);

// Function to compare the expected and actual output
int compare_output(const char *expected_output, const char *actual_output) {
    return strcmp(expected_output, actual_output) == 0;
}

// Mock function to simulate file creation for testing
void create_test_file() {
    // Ensure the directory exists
    system("mkdir -p /home/subbaramaiah_chevuru/subbu/subbu_project/Output_Files");

    // Debug: Check current working directory
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    }

    // Open the file with an absolute path
    FILE *fp = fopen("/home/subbaramaiah_chevuru/subbu/subbu_project/Output_Files/cheeti.txt", "w");
    if (fp == NULL) {
        perror("Unable to open file for test");
        exit(1);
    }

    // Write test data into the file
    fprintf(fp, "January\t: 1000\nFebruary\t: 1200\n");
    fprintf(fp, "Total :2200.00");
    fclose(fp);
}

// Updated test function
int test_manage() {
    // Create a file with known content for testing
    create_test_file();

    // Redirect stdout to capture print_list output
    FILE *output_file = fopen("test_output.txt", "w");
    if (output_file == NULL) {
        perror("Failed to open output file");
        return 0;
    }

    int stdout_fd = dup(fileno(stdout));  // Save original stdout
    freopen("test_output.txt", "w", stdout);  // Redirect stdout to file

    // Open the input file using absolute path
    FILE *fp = fopen("/home/subbaramaiah_chevuru/subbu/subbu_project/Output_Files/cheeti.txt", "r");
    if (fp == NULL) {
        perror("Failed to open input file for reading");
        fclose(output_file);
        return 0;
    }

    // Call the function to test
    print_list(fp);
    fclose(fp);  // Close input file after the test

    // Restore stdout
    fflush(stdout);
    dup2(stdout_fd, fileno(stdout));
    close(stdout_fd);
    fclose(output_file);

    // Read the output file content
    FILE *result_file = fopen("test_output.txt", "r");
    if (result_file == NULL) {
        perror("Failed to read test_output.txt");
        return 0;
    }

    char actual_output[1024];
    size_t n = fread(actual_output, sizeof(char), sizeof(actual_output) - 1, result_file);
    actual_output[n] = '\0';  // Null-terminate
    fclose(result_file);

    // Normalize newlines to prevent mismatches
    char *token = strtok(actual_output, "\r\n");
    char normalized_output[1024] = "";
    while (token) {
        strcat(normalized_output, token);
        strcat(normalized_output, "\n");
        token = strtok(NULL, "\r\n");
    }

    // Define expected output
    const char *expected_output = "January\t: 1000\nFebruary\t: 1200\nTotal :2200.00\n";

    // Debug prints
    printf("Expected Output:\n%s\n", expected_output);
    printf("Actual Output:\n%s\n", normalized_output);

    // Compare output
    return compare_output(expected_output, normalized_output) ? 1 : 0;
}
