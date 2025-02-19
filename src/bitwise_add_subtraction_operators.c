/****************************************************************/
/*	Name 	: Addition and Subtraction of two numbers using */
/*		  Bitwise Operators.				*/
/*	Author	: Subbaramaiah Chevuru				*/
/*								*/
/****************************************************************/

//==============================================================//
//		REVISION LOG					//
//==============================================================//
//  23-12-10	-	Initial Draft of the Program 		//
//  25-02-17	-	Improvements in the supporting functions//
//								//
//==============================================================//


//Header files
#include<stdio.h>
#include<stdlib.h>

//Supporting function to converting the decimal into binary
//by storing the remainders into an array and printing the
//stored array.
void decimal_to_binary(int x)
{
	int arr[32];
	if(x==0)
	{
		arr[0] =0;
		return;
	}
	int i = 0;
	while (x > 0){
		// storing remainder in binary array
		arr[i] = x % 2;
		x = x / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		printf("%d", arr[j]);
}

//Supporting function for the addition of two numbers using
//bitwise operators.
int bitwiseadd(int x, int y)
{
	while (y != 0)
	{
		int carry = x & y;
		x = x ^ y;
		y = carry << 1;
	}
	return x;
}
//Supporting function for the subtraction of two numbers using
////bitwise operators.
int subtraction(int x, int y)
{
	int temp = 0;
	// Subtract of two numbers
	while (y != 0)
	{
		temp = (~x) & y;
		x = x ^ y;
		y = temp << 1;
	}
	return x;
}

//Main starts here
#ifndef TESTING
int main()
{
	int a, b;
	printf("\n Enter the number a and b:");
	scanf("%d %d",&a, &b);
	printf("\n Binary Equivalent of a:");
	decimal_to_binary(a);
	printf("\n");
	printf("\n Binary Equivalent of a:");
	decimal_to_binary(b);
	printf("\n Addition of %d and %d is %d\n", a, b, bitwiseadd(a,b));
	printf("\n Subtraction of %d and %d is %d\n", a, b, subtraction(a,b));
	return 0;
}
#endif
