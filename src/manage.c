/********************************************************/
/*	Name	: Calculate the Cheeti			*/
/*	Author 	: Subbaramaiah Chevuru			*/
/*	Mail    : ram.subaram@gmail.com			*/
/*							*/
/********************************************************/

/********************************************************/
/*		REVISION LOG				*/
/********************************************************/
/* 24-11-02 - 	Initial Draft for the Cheet Program 	*/
/*		and save into a file.			*/
/*							*/
/********************************************************/
//Header Files
#include <stdio.h>
#include <stdlib.h>

// To print the list into the file.
void print_list(FILE *fp1)
{
    char ch;
    if (fp1 == NULL)
    {
        printf("\nFILE is Empty.....!!!!\n");
        exit(1);
    }
    else
    {
        ch = getc(fp1);
        while (ch != EOF)  // Use EOF instead of NULL to end the loop
        {
            printf("%c", ch);
            ch = getc(fp1);
        }
    }
    // Removed fclose(fp1) from here to avoid double free
}

#ifndef TESTING
// Main starts Here
int main() {
    int amount, i, n;
    float total = 0;
    char month[10];
    FILE *fp;
    fp = fopen("../Output_Files/cheeti.txt", "w+");
    printf("\nEnter the number of Months:\n");
    scanf("%d", &n);
    if (fp == NULL)
    {
        printf("\n Unable to open file.\n");
        exit(1);
    }
    else
    {
        fprintf(fp, "Month\t Amount\n");
        for (i = 0; i < n; i++)
        {
            printf("\nEnter the Month Name:");
            scanf("%s", month);
            printf("\nEnter the Amount:");
            scanf("%d", &amount);
            total = total + amount;
            fprintf(fp, "%s\t : %d \n", month, amount);
        }
    }
    fprintf(fp, "Total :%.2f", total);
    printf("\nTotal :%.2f", total);
    fclose(fp);  // Only fclose here in main
    return 0;
}
#endif

