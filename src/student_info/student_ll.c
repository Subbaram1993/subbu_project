//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
//		Program Name	:	Student Information Application		//
//		Author		:	Subbaramaiah Chevuru			//
//		Email		: 	ram.subaram@gmail.com			//
//										//
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//


//==============================================================================//
//				REVISON LOG					//
//==============================================================================//
//	Date 		-	History	and Updates				//
//==============================================================================//
//	2025/03/21	-	Added the Initial Draft of the Student 		//
//				Information Application using C. It implements	//
//				the Create, Update, Search and Display the 	//
//				Student information by searching with Name or 	//
//				Roll number. 					//
//	2025/03/23	-	Updated the display() to display_student() for	//
//				testing purpose.				//
//										//
//==============================================================================//

//Header Files (Standard)
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>

// User defined Header File.
#include "student_info.h"

//Global Student Variable.
Student *s=NULL;

//Macros 
#define FILENAME "students.dat"

//Functions to help the operations on Student Details.
void save_to_file(Student *s);
Student* load_from_file(Student *s);
Student* create_details(Student *s);
char* grade(float percent, bool use_color);
void display_student(Student *s, int search_mode);
void rollno_search(Student *s);
void name_search(Student *s);
void search_student(Student *s);
void update_name(Student *s);
void update_marks(Student *um);
void update_details(Student *s);
void info();
void free_memory(Student *s);

// Save the Details to the database (file).
void save_to_file(Student *s)
{
	int i;
	float total, percentage;
	FILE *fp = fopen(FILENAME, "w");
	if(fp==NULL){
		printf("\nUnable to open the file.\n");
		return;
	}
	Student *p=s;
	while(p){
		total=0;
		fprintf(fp, "%d\t%s\t\t", p->rollno, p->name);
		for(i=0;i<6;i++){
			total += p->marks[i];
			fprintf(fp, " %.2f\t", p->marks[i]);
		}
		percentage  = (total / 600) * 100;
		fprintf(fp, "%.2f\t%s\n", total, grade(percentage, false));
		p = p->next;
	}
	fclose(fp);
}

// Fetching or Loading the Student Details from the Database(file).
Student* load_from_file(Student *s) {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("\nUnable to open the file.\n");
        return NULL;
    }

    Student *head = NULL, *tail = NULL;
    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        Student *temp = (Student*)malloc(sizeof(Student));
        if (!temp) {
            printf("Memory allocation failed!\n");
            break;
        }

        int rollno;
        char name[50];
        float marks[6];

        if (sscanf(line, "%d %s %f %f %f %f %f %f", &rollno, name, 
                   &marks[0], &marks[1], &marks[2], 
                   &marks[3], &marks[4], &marks[5]) != 8) {
            printf("Skipping malformed record: %s", line);
            free(temp);
            continue;
        }

        if (rollno <= 0 || rollno > 9999) {
            printf("Skipping invalid Roll No.: %d\n", rollno);
            free(temp);
            continue;
        }

        temp->rollno = rollno;
        strcpy(temp->name, name);
        for (int i = 0; i < 6; i++) {
            temp->marks[i] = marks[i];
        }
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            tail->next = temp;
        }
        tail = temp;
    }

    fclose(fp);
    return head;
}

// This function Create the Student Details and Save them into the Database
Student* create_details(Student *s)
{
	FILE *fp = fopen(FILENAME, "a");
	if(fp==NULL){
		printf("\nUnable to open the file.\n");
		return s;
	}

	struct Student *p, *q=s, *temp=NULL;
	int i;
	float total, percentage;

	if(q != NULL){
		while(q->next){
			q= q->next;
		}
	}

	while(1){
		total =0;
		p = (Student*)malloc(sizeof(Student));
		if(!p){
			printf("\nMemory allocation failed.\n");
			break;
		}
		
		printf("\nEnter the Roll Number: \n");
		scanf("%d",&p->rollno);
		if(p->rollno ==0){ 
			free(p); 
			break;
		}

		temp =s;
		while(temp != NULL){
			if(temp->rollno == p->rollno){
				printf(RED"\nError: Roll Number %d is already exists. Please enter unique Roll Number:\n"RESET, p->rollno);
				free(p);
				p = NULL;
				break;
			}
			temp = temp->next;
		}
		if(!p) continue;
		
		printf("\nEnter the Name of the Student: \n");
		scanf("%s", p->name);
		
		printf("\nEnter the Marks for 6 Subjects: \n");
		for(i=0;i<6;i++){
			scanf("%f", &p->marks[i]);
		}
		
		p->next = NULL;
		if(s==NULL){
			s = p;
		}
		else{
			q->next = p;
		}
		q = p;

		//Appending the data into the file
		fprintf(fp, "%d\t%s\t\t", p->rollno, p->name);
		for(i=0;i<6;i++){
			total += p->marks[i];
			fprintf(fp, " %.2f\t", p->marks[i]);
		}
		percentage  = (total / 600) * 100;
		fprintf(fp, "%.2f\t%s\n", total, grade(percentage, false));
		printf("\nStudent Details added Successfully.\n");
	}

	fclose(fp);
	return s;
}

//This function calculates the Grade based on the Percentage for the Student.
char* grade(float percent, bool use_color)
{
    if (use_color) {
        if (percent >= 80) return GREEN "A+" RESET;
        else if (percent >= 75) return GREEN "A" RESET;
        else if (percent >= 60) return BLUE "B" RESET;
        else if (percent >= 50) return ORANGE "C" RESET;
        else return RED "D" RESET;
    } else {
        if (percent >= 80) return "A+";
        else if (percent >= 75) return "A";
        else if (percent >= 60) return "B";
        else if (percent >= 50) return "C";
        else return "D";
    }
}

// Displaying or Printing the Student Information 
// It has two modes 
// 1 -> Displays Only one Student Information or Details while Search 
//      or Update.
// 0 -> Displays the information or details for all Students.
void display_student(Student *s, int search_mode) {
    int i, totalStudents = 0, passCount = 0, failCount = 0;
    float total, percentage, grand_total = 0;
    Student *r = s;

    if (s == NULL) {
        printf("\nNo student records found.\n");
        return;
    }

    if (!search_mode) {
        printf("\n=== Displaying All Student Records ===\n");
    }

    while (r != NULL) {
        total = 0;
        int isPass = 1;

        printf("\n+========================================+\n");
        printf("|        STUDENT DETAILS (Roll No: " BLUE "%d" RESET ")    |\n", r->rollno);
        printf("+========================================+\n");
        printf("| Name   : " BLUE "%-30s" RESET "|\n", r->name);
        printf("+----------------------------------------+\n");
        printf("| Subject |   Marks  |  Result  \t |\n");
        printf("+----------------------------------------+\n");

        for (i = 0; i < 6; i++) {
            total += r->marks[i];
            if (r->marks[i] < 35) {
                isPass = 0; 
            }
            printf("|  %-3d    |   %-6.2f |    %s    \t |\n", i + 1, r->marks[i],
                   (r->marks[i] >= 35) ? GREEN "PASS" RESET : RED "FAIL" RESET);
        }

        percentage = (total / 600) * 100;
        printf("+----------------------------------------+\n");
        printf("| Total : %-6.2f | Grade: %s \t\t |\n", total, grade(percentage, true));
        printf("+========================================+\n");

        totalStudents++;
        grand_total += total;
        if (isPass)
            passCount++;
        else
            failCount++;

        if (search_mode) break;  
        r = r->next;
    }

    if (!search_mode) {
        float passPercentage = (passCount * 100.0) / totalStudents;
        float failPercentage = (failCount * 100.0) / totalStudents;

        printf("\n+==============================================================+\n");
        printf("|" BLUE " TOTAL STUDENTS:" RESET " %d  | " GREEN " PASS: " RESET " %d (%.2f%%)  | " RED " FAIL:" RESET " %d (%.2f%%) |\n",
               totalStudents, passCount, passPercentage, failCount, failPercentage);
        printf("|" BLUE " AVERAGE SCORE:" RESET "  %.2f \t\t\t\t       |\n", grand_total / (totalStudents * 6));
        printf("+==============================================================+\n");
    }
}

// This is the helper function searched based on the Student Roll Number and 
// returns the Student information or Details if its found.
void rollno_search(Student *s)
{
	int rno, found=0;
	struct Student *r=s;
	if(s==NULL)
	{
		printf("\nNo details found...\n");
		return;
	}
	printf("\nEnter the Roll number :  ");
	scanf("%d",&rno);
	while(r!=NULL){
		if(r->rollno == rno){
			if(!found){
				printf("\nStudent Details are Found as below:.....\n");
			}
			found=1;
			display_student(r, 1);
		}
		r = r->next;
	}

	if(!found){
		printf("\nStudent Details Not Found.....\n");
	}

	printf("\n");
}

// This is the helper function searched based on the Student Name and
// returns the Student information or Details if its found.
void name_search(Student *s) {
    if (s == NULL) {
        printf("\nNo student records found.\n");
        return;
    }
    
    char search_name[20];
    printf("\nEnter Student Name to Search: ");
    scanf("%19s", search_name);
    
    Student *temp = s;
    while (temp != NULL) {
        if (strcmp(temp->name, search_name) == 0) {
            printf("\nStudent Details Found:\n");
            display_student(temp, 1);
            return;
        }
        temp = temp->next;
    }
    printf("\nStudent with Name \"%s\" not found.\n", search_name);
}

// This function searched based on the Student Roll Number or Name 
// and returns the Student information or Details if its found.
void search_student(Student *s)
{
	struct Student *p=s;
	int opt;
	if(p==NULL)
	{
		printf("\nNo Student Records Available....!!\n");
		return ;
	}
	printf("\nEnter the option to search by RollNo or Name (1 or 2) ? \n");
	scanf("%d", &opt);
	switch(opt){
		case 1: rollno_search(p);
			break;
		case 2: name_search(p);
			break;
		default:printf("\nInvalid Option....? Select 1 or 2 :)");
	}
	printf("\n");
}

// This helper function update the Name details for the Student based on 
// Roll Number and returns the Student information or Details if its found.
void update_name(Student *s) {
    int roll;
    char new_name[50];
    printf("Enter Roll Number to update name: ");
    scanf("%d", &roll);
    Student *p = s;
    while (p) {
        if (p->rollno == roll) {
            printf("Enter New Name: ");
            scanf("%s", new_name);
            strcpy(p->name, new_name);
            save_to_file(s);
            printf("Name Updated Successfully.\n");
            return;
        }
        p = p->next;
    }
    printf("Record not found.\n");
}

// This helper function update the Marks details for the Student based on
// Roll Number and returns the Student information or Details if its found.
void update_marks(Student *um)
{
	Student *upm=um;
	int sub, rono;
	float umarks;
	printf("\nEnter the Student RollNo to update the marks: \n");
	scanf("%d", &rono);
	if(um==NULL){
		printf("\nNo Records Found....!!!!\n");
		return;
	}
	while(upm!=NULL){
		if(upm->rollno == rono){
			printf("\nEnter the Subject(0-5) and Marks to update:\n");
			scanf("%d %f", &sub, &umarks);
			if(sub < 0 || sub >= 6){
				printf("\nInvalid Subject Index, it should be (0-5).\n");
				return;
			}	       
			upm->marks[sub] = umarks;
			save_to_file(um);
			printf("\nMarks for the Student with RollNo:%d successfully updated.\n", upm->rollno);
			display_student(upm, 1);
			return;
		}
		upm = upm->next;
	}
	printf("\nStudent with RollNo: %d not found!\n", rono);
}

// Update function that updates the Student details like Name and Marks based 
// on Searching by Name or RollNo  
void update_details(Student *s)
{
	int roll, ch;
	if(s==NULL)
	{
		printf("\nNo Student Records found....!!\n");
		return;
	}
	printf("\nWhat do you want update(1-Name, 2-Marks) in Student Records.\n");
	scanf("%d", &ch);
	switch(ch){
		case 1: update_name(s);
			break;
		case 2: update_marks(s);
			break;
		default: printf("\nInvalid Option....!!!\n");
	}
}

// Menu Driven function that displays the options to select the task.
void info()
{
	printf(CYAN"\n$====================================================$");
	printf(CYAN"\n$"YELLOW"\t WELCOME TO STUDENT INFORMATION"CYAN"\t\t     $");
	printf(CYAN"\n$====================================================$");
	printf(CYAN"\n$"MAGENTA"  1. Create New Student Details."CYAN"\t\t     $");
	printf(CYAN"\n$"MAGENTA"  2. Search Student Details."CYAN"\t\t\t     $");
	printf(CYAN"\n$"MAGENTA"  3. Update Student details."CYAN"\t\t\t     $");
	printf(CYAN"\n$"MAGENTA"  4. Display.		    "CYAN"\t\t\t     $");
	printf(CYAN"\n$"MAGENTA"  5. Close the Application. "CYAN"\t\t\t     $");
	printf(CYAN"\n$====================================================$\n"RESET);
}

// Allocate Memory Freeing and set to NULL, since no memory leaks. 
void free_memory(Student *s)
{
	printf("\nFreeing the records before exit....!\n");
	Student *temp;
	while(s!=NULL)
	{
		temp = s;
		s = s->next;
		free(temp);
	}
	s = NULL;
}

/* Main Starts here to display the Menu Driven Student Record Database.
 * This function helps to do the tasks for create, search, update and 
 * display the student details like RollNo, Name and Marks for 6 Subjects.
*/

#ifndef TESTING
int main()
{
	int choice;
	s = load_from_file(s);
	while(1){
		info();
		printf("\nEnter the Choice (1-5) ? \n");
		scanf("%d", &choice);
		switch(choice){
			case 1: s = create_details(s);
				break;
			case 2: search_student(s);
				break;
			case 3: update_details(s);
				break;
			case 4: display_student(s,0);
				break;
			case 5: free_memory(s);
				exit(1);
				break;
			default: printf("\nInvalid Option");
		}
	}
	return 0;
}
#endif
