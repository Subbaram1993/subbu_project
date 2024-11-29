/****************************************************************
 *  Program Name : Conversion of Numbers into Digits		*
 *  Authour: Subbaramaiah Chevuru				*
 *  Email : ram.subaram@gmail.com				*
 *								*
 *  About:							*
 *  This Program Converts the Number into words entered by the 	*
 *  User and prints in Words format.				*
 *								*
 *								*	
 ****************************************************************/

/****************************************************************
 * 			REVISION LOG				* 			
 ****************************************************************/
/*240818  -   Initial Draft for the conversion of Numbers into 	*
 * 	      words						*
 * 	      							*/
/****************************************************************/

//Including the Libraries
#include <stdio.h>

/* To Print the Numbers into words */
void print_to_letters(int n)
{
        int thousands, hundreds, tens,ones;
        char *ones_word[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        char *tens_word[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        char *teens_word[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
        thousands = n / 1000;
        n = n % 1000;
        hundreds = n / 100;
        n = n % 100;
        tens = n / 10;
        ones  = n % 10;

	//If Thousands  greater than zero
        if( thousands > 0)
        {
            printf("\n %s thousand ",ones_word[thousands]);
        }
	//If Hundreds greater than  zero
        if(hundreds > 0)
        {
            printf(" %s hundred ", ones_word[hundreds]);
        }
        if (tens > 1) 
        {
            printf("%s ", tens_word[tens]);
            if (ones > 0)
            {
                printf("%s ", ones_word[ones]);
            }
        } 
        else if (tens == 1) 
        {
            printf("%s ", teens_word[ones]);
        } 
        else if (ones > 0) 
        {
            printf("%s ", ones_word[ones]);
        }
}

//Main starts here
int main()
{
        int num;
        printf("\n Enter the number : ");
        scanf("%d", &num);

        print_to_letters(num);

        return 0;
}
