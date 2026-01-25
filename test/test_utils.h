#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to open files safely in TEST_OUTPUT_DIR
static inline FILE* open_test_file(const char *filename, const char *mode) {
        const char *dir = getenv("TEST_OUTPUT_DIR");
            if (!dir || strlen(dir) == 0) dir = "."; // fallback to current directory

                char path[1024];
                    snprintf(path, sizeof(path), "%s/%s", dir, filename);

                        FILE *f = fopen(path, mode);
                            if (!f) {
                                        fprintf(stderr, "Failed to open test file: %s\n", path);
                                            }
                                return f;
}

#endif // TEST_UTILS_H

