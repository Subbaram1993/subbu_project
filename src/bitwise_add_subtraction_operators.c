#include<stdio.h>
#include<stdlib.h>

void decimal_to_binary(int x)
{
	int arr[16];
	if(x==0)
	{
		arr[0] =0;
		exit(1);
	}
	else
	{
		int i = 0;
		while (x > 0)
		{
			// storing remainder in binary array
			arr[i] = x % 2;
			x = x / 2;
			i++;
		}
		for (int j = i - 1; j >= 0; j--)
			printf("%d", arr[j]);
	}
}

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

int subtraction(int x, int y)
{
	int temp = 0;
	// Subtract of two numbers
	while (y != 0)
	{
		temp = ((~x) & y) << 1;
		x = x ^ y;
		y = temp;
	}
	return x;
}

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
