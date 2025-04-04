#ifndef manage_H
#define manage_H

void print_list(FILE *fp1);
    // Removed fclose(fp1) from here to avoid double free;

#endif // manage_H
