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
//									//
//======================================================================//

// Header Files
#include <stdio.h>
#include <stdlib.h>

//Main Starts Here
int main() {
    int *a;
    int i,min,max,n;
    printf("\n Enter the number of elements:\n"),
    scanf("%d", &n);
    printf("\n Enter %d numbers:\n", n);
    a = (int*)malloc(n*sizeof(a));
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n The Numbers in the array are: \n");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    min = a[0];
    max = a[0];
    for(i=0;i<n;i++)
    {
        if(a[i] < min)
        {
            min = a[i];
        }
        if(a[i] > max)
        {
            max = a[i];
        }
    }

    printf("\n Minimum value is %d\n Maximum Value is %d\n",min,max);

    return 0;
}
