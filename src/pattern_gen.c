/****************************************************************/
/*	Name	:	Pattern Printing			*/
/*	Author	:	Subbaramaiah Chevuru			*/
/*								*/
/*1								*/
/*1 3								*/
/*1 3 5								*/
/*1 3 5 7							*/
/*1 3 5 7 9							*/
/*2 4 6 8 10							*/
/*2 4 6 8							*/
/*2 4 6								*/
/*2 4								*/
/*2								*/
/****************************************************************/

/****************************************************************/
/*			REVISION LOG				*/
/****************************************************************/
/*  25-01-2025 	-	Initial Draft of the Program		*/
/*								*/
/****************************************************************/

//Header Files
#include <stdio.h>

//Main starts Here
int main()
{
	int i,j,k,n=10;

	//Printing the Upper part of the pattern
	for(i=1;i<=n/2;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d ", (2*j-1));
		}
		printf("\n");
	}

	//Printing the Lower part of the pattern
	for(i=n/2;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d ", (2*j));
		}
		printf("\n");
	}

	return 0;
}
