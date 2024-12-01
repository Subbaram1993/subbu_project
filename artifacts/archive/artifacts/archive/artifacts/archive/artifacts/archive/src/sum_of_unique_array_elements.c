/************************************************************************/
/*	Name   :  Sum of Unique Elements in the Array.			*/
/*	Author :  Subbaramaiah Chevuru					*/
/*	Mail   :  ram.subaram@gmail.com					*/
/*									*/
/************************************************************************/

//======================================================================//
//									//
//			REVISION LOG					//
//									//
//======================================================================//
//									//
//									//	
//	24-09-08 - 	Initial Draft of the Program.			//
//									//
//======================================================================//

//Header Files
#include <stdio.h>
#include <stdlib.h>


//Main function starts here

int main()
{
	int i,j,n,c=0,sum=0,*a;
	printf("\nEnter the number of Elements:\n");
	scanf("%d", &n);

	a = (int *)malloc(n*sizeof(int *));

	//Reading the Elements in the Array.
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}

	//Sum of the Unique Elements in the Array
	for(i=0;i<n;i++)
	{
		c =0;
		for(j=0;j<n;j++)
		{
			if( i != j && a[i] == a[j])
			{
				c =1;
				break;
			}
			if(c==0)
			{
				printf("%d", a[i]);
				sum += a[i];
			}
		}
	}
	printf("\n Sum is %d\n.", sum);
	return 0;

}

