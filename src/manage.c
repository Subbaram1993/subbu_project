// Online C compiler to run C program online

#include <stdio.h>

#include <stdlib.h>

void print_list(FILE *fp1)
{
    char ch;
    fp1 = fopen("cheeti.txt","r");
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
