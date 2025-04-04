#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdbool.h>

#define SRC_DIR "src/"
#define INC_DIR "include/"

// Ensure the include directory exists
void ensure_directory_exists(const char *dir) {
    struct stat st;
    if (stat(dir, &st) == -1) {
        printf("Creating directory: %s\n", dir);
        if (mkdir(dir, 0777) != 0) {
            perror("Failed to create directory");
            exit(EXIT_FAILURE);
        }
    }
}

// Check if a line looks like a function prototype
bool is_function_prototype(const char *line) {
    if (strchr(line, '(') && strchr(line, ')') && !strstr(line, "printf") && !strstr(line, "scanf") &&
        !strstr(line, "while") && !strstr(line, "return") && !strstr(line, "if") &&
        !strstr(line, "for") && !strstr(line, "switch")) {
        return true;
    }
    return false;
}

// Extract function prototypes from a .c file
void extract_function_prototypes(FILE *src, FILE *hdr) {
    char line[512];

    while (fgets(line, sizeof(line), src)) {
        // Ignore preprocessor directives and comments
        if (line[0] == '#' || line[0] == '/' || line[0] == '\n') {
            continue;
        }

        // Check if the line is a function declaration
        if (is_function_prototype(line)) {
            // Ensure the function prototype ends with a semicolon
            if (strchr(line, '{') == NULL && strchr(line, ';') == NULL) {
                size_t len = strlen(line);
                if (len > 0 && line[len - 1] == '\n') {
                    line[len - 1] = '\0'; // Remove newline
                }
                fprintf(hdr, "%s;\n", line);
            }
        }
    }
}

// Generate a header file for the given .c file
void generate_header_file(const char *filename) {
    char src_path[256], hdr_path[256], base[256];

    snprintf(src_path, sizeof(src_path), "%s%s", SRC_DIR, filename);
    snprintf(base, sizeof(base), "%s", filename);
    char *dot = strrchr(base, '.');
    if (dot) *dot = '\0'; // Remove file extension

    snprintf(hdr_path, sizeof(hdr_path), "%s%.200s.h", INC_DIR, base);

    FILE *src = fopen(src_path, "r");
    if (!src) {
        perror("Failed to open source file");
        return;
    }

    FILE *hdr = fopen(hdr_path, "w");
    if (!hdr) {
        perror("Failed to create header file");
        fclose(src);
        return;
    }

    // Write header guard
    fprintf(hdr, "#ifndef %s_H\n#define %s_H\n\n", base, base);

    // Extract and write function prototypes
    extract_function_prototypes(src, hdr);

    // End header file
    fprintf(hdr, "\n#endif // %s_H\n", base);

    fclose(src);
    fclose(hdr);
    printf("Generated: %s\n", hdr_path);
}

// Main function to scan the source directory
int main() {
    ensure_directory_exists(INC_DIR);

    DIR *dir = opendir(SRC_DIR);
    if (!dir) {
        perror("Failed to open source directory");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".c")) {
            generate_header_file(entry->d_name);
        }
    }

    closedir(dir);
    return EXIT_SUCCESS;
}
