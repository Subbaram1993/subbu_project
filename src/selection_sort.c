/*****************************************************************/
/*	Program Name : Selection Sort Using Arrays		 */
/*	Author: Subbaramaiah Chevuru				 */
/*	E-mail: ram.subaram@gmail.com				 */
/*								 */
/*****************************************************************/

/****************************************************************/
/*		REVISION LOG					*/
/****************************************************************/
/*	2024-09-03 -	Initial Draft for the Selection Sort	*/
/*			using the Arrays.			*/
/*								*/
/*								*/								
/****************************************************************/

//Header Files
#include <stdio.h>
#include <stdlib.h>

// Swapping function
void swap(int a[], int b[]){

	int t;

	t = *a;
	*a = *b;
	*b = t;
}

// Performs Selection Sort
void selection_sort(int a[], int n){
	int min,i,j;

	for(i=0;i<n-1;i++)
	{
		min = i;
		for(j=i+1;j<n;j++){
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		if(min!=i)
		{
			swap(&a[min],&a[i]);
		}
	}
}

// Printing the Array after sorting
void print_array(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ", a[i]);
	}
}

// Main Functions starts here
int main(){
	int *a,i,j,n;

	printf("\nEnter the Number of Elements: \n");
	scanf("%d",&n);
	a = (int *)malloc(n*sizeof(a));

	printf("\nReading the Elements: \n");
	for(i=0;i<n;i++){
		scanf("%d", a+i);
	}
	printf("\nElements in the Array are: \n");
	print_array(a,n);
	printf("\nSorting the Elements:\n\n");
	selection_sort(a,n);
	printf("\nAfter Sorting the Array: \n");
	print_array(a,n);
	printf("\n");

	free(a);

	return 0;
}
