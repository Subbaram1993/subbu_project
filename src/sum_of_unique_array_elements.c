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
//	24-12-01 -      Rewrite the logic into seperate function.	//
//======================================================================//

//Header Files
#include <stdio.h>
#include <stdlib.h>

// Function to sum unique elements in the array
int sum_of_unique_elements(int arr[], int size) {
    int i, j, c, sum = 0;

    // Sum of the unique elements in the array
    for(i = 0; i < size; i++) {
        c = 0;  // Variable to track if a number is a duplicate
        for(j = 0; j < size; j++) {
            if(i != j && arr[i] == arr[j]) {  // Check if arr[i] is duplicated
                c = 1;  // Found a duplicate
                break;
            }
        }
        if(c == 0) {  // If no duplicate, add to sum
            sum += arr[i];
        }
    }
    return sum;
}

#ifndef TESTING
// Main function starts here
int main() {
    int i, n;
    int *a;

    printf("\nEnter the number of elements:\n");
    scanf("%d", &n);

    // Allocate memory for the array
    a = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if(a == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // Exit if memory allocation fails
    }

    // Reading the elements in the array
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Calculate and print the sum of unique elements
    int sum = sum_of_unique_elements(a, n);
    printf("\nSum of unique elements is: %d\n", sum);

    // Free the allocated memory
    free(a);

    return 0;
}
#endif

