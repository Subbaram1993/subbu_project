#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <stdio.h>
#include <stdlib.h>

// ANSI color codes for formatted output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define ORANGE  "\x1B[38;2;255;165;0m"

typedef struct Student {
    int rollno;
    char name[100];
    float marks[6];
    struct Student *next;
} Student;

void save_to_file(Student *s);
Student* load_from_file(Student *s);
Student* create_details(Student *s);
char* grade(float percent, bool use_color);
void display(Student *s, int search_mode);
void rollno_search(Student *s);
void name_search(Student *s);
void search_student(Student *s);
void update_name(Student *s);
void update_marks(Student *um);
void update_details(Student *s);
void info();
void free_memory(Student *s);


#endif // STUDENT_INFO_H
