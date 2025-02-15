#include<stdio.h>
#include<stdlib.h>

void display(int *a, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ", *(a+i));
	}
}

void bubble_sort(int *a, int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("\n");
}

int binary_search(int *a, int n, int target)
{
	int first=0,last=n-1,mid;
	while(first <= last)
	{
		mid = first + (last-first)/2;
		if(target == a[mid])
			return mid;
		if(target > a[mid]){
			first = mid + 1;
		}
		else{
			last = mid - 1;
		}
	}
	return -1;
}

#ifndef TESTING
int main()
{
	int *a,i,j,n,target,pos;
	printf("\nEnter the number of elements in the array.\n");
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int));
	printf("\nEnter the %d elements.\n",n);
	for(i=0;i<n;i++){
		scanf("%d", (a+i));
	}
	printf("\nThe elements are:\n");
	display(a,n);
	printf("\nAfter sorting the elements in the array:\n");
	bubble_sort(a,n);
	display(a,n);
	printf("\nEnter the element to be searched in the array.\n");
	scanf("%d", &target);
	pos = binary_search(a, n, target);
	(pos>0)?printf("\nThe element %d is present at %d position.\n",target,pos+1):printf("\nThe element %d is not found in the array.\n", target);
	free(a);
	return 0;
}
#endif
