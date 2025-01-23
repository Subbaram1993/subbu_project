/****************************************************************/
/*	Name	:	Print the Selective characters from the */
/*			given String.				*/
/*	Author	:	Subbaramaiah Chevuru			*/
/*								*/
/****************************************************************/


//Header files
#include<stdio.h>

//Function to print the Corresponding index characters from the 
//given string 
//E.g:1. I/p: "Hi am very", O/p : Hmr
//E.g:2. I/p: "Have a nice day". O/p: H*c*
//
void print_corresp_index_char(char *str)
{
	int i=0,j=0,word=0;
	while(str[i] != '\0')
	{
		while(str[i] == ' ')
		{
			i++;
		}
		if(str[i] !='\0')
		{
			word = i;
			while(str[i] != ' ' && str[i] != '\0')
			{
				i++;
			}
			if(j<i-word)
			{
				printf("%c", str[word+j]);
			}
			else{
				printf("*");
			}
			j++;
		}
	}
	printf("\n");

}

//Main starts here
int main()
{
	char ch[25];
	printf("\n Enter the sentence :\n");
	scanf("%[^\n]s", ch);
	print_corresp_index_char(ch);
	return 0;
}
