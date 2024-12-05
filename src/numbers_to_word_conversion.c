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
#include <stdlib.h>
#include <string.h>

// Function to convert number to words
const char* print_to_letters(int n) {
    static char result[100];  // Static buffer to hold the result string
    char *ones_word[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *tens_word[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *teens_word[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    int thousands, hundreds, tens, ones;

    // Check if the number is negative
    if (n < 0) {
        n = -n; // Make the number positive for processing
        strcpy(result, "negative "); // Add "negative" at the beginning
    } else {
        result[0] = '\0';  // Clear the result string if number is positive
    }

    thousands = n / 1000;
    n = n % 1000;
    hundreds = n / 100;
    n = n % 100;
    tens = n / 10;
    ones  = n % 10;

    // If Thousands are greater than zero
    if (thousands > 0) {
        strcat(result, ones_word[thousands]);
        strcat(result, " thousand ");
    }

    // If Hundreds are greater than zero
    if (hundreds > 0) {
        strcat(result, ones_word[hundreds]);
        strcat(result, " hundred ");
    }

    // Handle tens and ones
    if (tens > 1) {
        strcat(result, tens_word[tens]);
        if (ones > 0) {
            strcat(result, "-");
            strcat(result, ones_word[ones]);
        }
    } else if (tens == 1) {
        strcat(result, teens_word[ones]);
    } else if (ones > 0) {
        strcat(result, ones_word[ones]);
    }

    // If no number is entered (0)
    if (n == 0 && result[0] == '\0') {
        strcpy(result, "zero");
    }

    return result;
}

#ifndef TESTING
// Main function
int main() {
    int num;
    printf("\n Enter the number: ");
    scanf("%d", &num);

    // Print the number in words
    printf("%s\n", print_to_letters(num));

    return 0;
}
#endif

