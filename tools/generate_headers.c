#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define SRC_DIR "src/"
#define INC_DIR "include/"

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

void generate_header_file(const char *filename) {
    char src_path[256], hdr_path[256], base[256];

    snprintf(src_path, sizeof(src_path), "%s%s", SRC_DIR, filename);
    snprintf(base, sizeof(base), "%s", filename);
    char *dot = strrchr(base, '.');
    if (dot) *dot = '\0';  // Remove file extension

    snprintf(hdr_path, sizeof(hdr_path), "%s%s.h", INC_DIR, base);

    FILE *hdr = fopen(hdr_path, "w");
    if (!hdr) {
        perror("Failed to create header file");
        return;
    }

    fprintf(hdr, "#ifndef %s_H\n#define %s_H\n\n", base, base);
    fprintf(hdr, "\n#endif // %s_H\n", base);
    fclose(hdr);

    printf("Generated: %s\n", hdr_path);
}

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
