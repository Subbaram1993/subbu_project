//////////////////////////////////////////////////////////////////////////
//	Name 	:	Maximum and Minimum number in the Array		//
//	Author  :	Subbaramaiah Chevuru				//
//									//
//////////////////////////////////////////////////////////////////////////

//======================================================================//
//			REVISION LOG					//
//======================================================================//
// Date 		What						//
//======================================================================//
// 2024-11-06	-	Initial Version of the C Program.		//
// 2024-12-01   -	Rewrite the logic in seperate function.		//
//======================================================================//

#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum and minimum elements in the array
void find_min_max(int a[], int n, int *min, int *max) {
    if (n <= 0) {
        printf("Error: Array size must be greater than 0.\n");
        return;
    }

    *min = a[0];
    *max = a[0];

    for (int i = 1; i < n; i++) { // Start from i = 1 since we already initialized min and max to a[0]
        if (a[i] < *min) {
            *min = a[i];
        }
        if (a[i] > *max) {
            *max = a[i];
        }
    }
}

#ifndef TESTING
//Main Starts Here
int main() {
    int *a;
    int i, min, max, n;
    printf("\n Enter the number of elements:\n");
    scanf("%d", &n);
    printf("\n Enter %d numbers:\n", n);
    a = (int*)malloc(n * sizeof(int)); // Correct memory allocation

    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\n The Numbers in the array are: \n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    // Call find_min_max function
    find_min_max(a, n, &min, &max);

    printf("\n Minimum value is %d\n Maximum Value is %d\n", min, max);

    free(a); // Free dynamically allocated memory
    return 0;
}
#endif
