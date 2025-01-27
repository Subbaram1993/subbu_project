/****************************************************************/
/*	Name	:	Sum of the Octets in the IP Address	*/
/*	Author	:	Subbaramaiah Chevuru			*/
/*								*/
/****************************************************************/

//Header files
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

//Function to convert the string into the integer
//E.g: "1234" -> 1234
int ascii_to_integer(char *str)
{
    int res=0,i=0;
    while(str[i] !='\0')
    {
        res = res * 10 + (str[i]- '0');
        i++;
    }
    return res;
}

//Function if the Octet string contains any character
//E.g: 5c -> return 0
int is_alpha(char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        if(((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
        {
            return 0;
        }
       i++;
    }
    return 1;
}

//Main Starts Here
int main() {
    char input_str[20], temp_res[20];
    int i=0,j=0,octets=0,count, sum=0;
    printf("\nenter the Input String as in IPv4 format.\n");
    scanf("%s", input_str);    

    while(input_str[i]!= '\0')
    {
        if(input_str[i] == '.')
        {
            i++;
        }
        j=0;
        while(input_str[i] != '.' && input_str[i] != '\0')
        {
            temp_res[j] = input_str[i];
            i++;
            j++;
        }
        temp_res[j] ='\0';
        if(!is_alpha(temp_res)){
            printf("\nIP is not valid.\n");
            exit(1);
        }
        count = ascii_to_integer(temp_res);
        if(count < 0 && count > 255)
        {
            printf("\n The Octet in the IP should not greater than 255 or less than 0.\n");
            exit(1);
        }
        octets++;
        sum += count;
    }
    (octets<4)?printf("\n Your IP: %s has only %d Octets.\n", input_str, octets):printf("\nSum:%d\n", sum);
   return 0;
}
