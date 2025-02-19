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

//To print the list into the file.
void print_list(FILE *fp1)
{
    char ch;
    fp1 = fopen("../Output_Files/cheeti.txt","r");
    if(fp1 == NULL)
    {
        printf("\nFILE is Empty.....!!!!\n");
        exit(1);
    }
    else
    {
        ch = getc(fp1);
        while(fp1!= NULL && ch != '\0')
        {
            printf("%c",ch);
            ch = getc(fp1);
        }
    }
    fclose(fp1);
}

//Main starts Here
int main() {
    int amount,i,n;
    float total=0;
    char month[10];
    FILE *fp;
    fp = fopen("cheeti.txt","w+");
    printf("/nEnter the number of Months:\n");
    scanf("%d",&n);
    if(fp == NULL)
    {
        printf("\n Unable to open file.\n");
        exit(1);
    }
    else
    {
       fprintf(fp,"Month\t Amount\n");
       for(i=0;i<n;i++)
       {
           printf("\n Enter the Month Name:");
           scanf("%s",month);
           printf("\nEnter the Amount:");
           scanf("%d", &amount);
           total = total + amount;
           fprintf(fp,"%s\t : %d \n",month,amount);
       }
    }
    //print_list(fp);
    fprintf(fp,"Total :%.2f",total);
    printf("\n Total :%.2f",total);
    fclose(fp);
    return 0;
}
