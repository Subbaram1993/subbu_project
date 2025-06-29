/************************************************************************/
/*	Name 	:	Temperature Converter.				*/
/*	Author	:	Subbaramaiah Chevuru				*/
/*									*/
/************************************************************************/

/************************************************************************/
/*			REVISION LOG					*/
/************************************************************************/
/*	25-06-28	-	Initial Draft of the Program		*/
/*	25-06-29	-	Indentation Correction.			*/
/************************************************************************/


//Header Files
#include <stdio.h>


//Function to convert to Celsius to Fahrenheit and Celsius to Kelvin
void convertCelsius(float c)
{
	printf("\nEntered the Temperature :%.2f", c);
	printf("\nTemp. in Fahreheit is %.2fF", (c * 9/5) + 32);
	printf("\nTemp. in Kelvin is %.2fK\n", c + 273.15);
}

//Function to convert Fahrenheit to Celsius and Fahrenheit to Kelvin
void convertFahrenheit(float f)
{
	float C = (f -32) * 5 /9 ;
	printf("\nEntered the Temperature :%.2f", f);
	printf("\nTemp. in Celsius is %.2fC", C);
	printf("\nTemp. in Kelvin is %.2fK\n", C + 273.15);
}

//Function to convert from Kelvin to Celsius and Kelvin to Fahrenheit
void convertKelvin(float k)
{
	float kel = k - 273.15;
	printf("\nEntered the Temperature :%.2f", k);
	printf("\nTemp. in Celsius is %.2fC", kel);
	printf("\nTemp. in Fahrenheit is %.2fF\n", (kel *9 /5) + 32);
}


//Main starts here
int main()
{
	int choice;
	float temp;

	printf("\nTemperature Converter\t\n");
	printf("1. Celsius\t\n");
	printf("2. Fahrenheit\t\n");
	printf("3. Kelvin\t\n");
	printf("\nEnter your choice....\n");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1: printf("\nEnter the Temperature in Celsius:\n");
			scanf("%f", &temp);
			convertCelsius(temp);
			break;
		case 2: printf("\nEnter the Temperature in Fahrenheit:\n");
			scanf("%f", &temp);
			convertFahrenheit(temp);
			break;
		case 3: printf("\nEnter the Temperature in Celsius:\n");
			scanf("%f", &temp);
			convertKelvin(temp);
			break;
		default: printf("\nInvalid Choice Displaying the Celsius...\n");
			 printf("\nEnter the Temperature in Celsius:\n");
			 scanf("%f", &temp);
			 convertCelsius(temp);
	}
	return 0;
}
