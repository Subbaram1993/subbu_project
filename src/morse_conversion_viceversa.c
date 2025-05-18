/****************************************************************/
/*	Name 	:	Morse Code Conversion			*/
/*								*/
/*	Author	:	Subbaramaiah Chevuru			*/
/*								*/
/*								*/
/****************************************************************/

//==============================================================//
//			REVISION LOG				//	
//==============================================================//
//								//
//	2025-05-18	-	Initial Draft for the Morse	//
//				Code Conversion and Convert it  //
//				into the Original		//
//								//
//								//
//==============================================================//

//Header Files
#include<stdio.h>
#include<string.h>

//Struct Declaration for Morse code.
typedef struct Morse_Sym{
	char morse_sym[6];
}Morse_Sym;


// Morse Code Table: Alphabets         Numbers
// Format:            <Char> <Morse>   | <Char> <Morse>

 /*
========================================================
A  .-            | K  -.-           | U  ..-           |
B  -...          | L  .-..          | V  ...-          | 
C  -.-.          | M  --            | W  .--           | 
D  -..           | N  -.            | X  -..-          | 
E  .             | O  ---           | Y  -.--          | 
F  ..-.          | P  .--.          | Z  --..          | 
G  --.           | Q  --.-          | Z  --..          |
H  ....          | R  .-.           | Z  --..          | 
I  ..            | S  ...           | Z  --..          |
J  .---          | T  -             | Z  --..          | 

0  -----	 |
1  .----	 |
2  ..---	 |
3  ...--	 |
4  ....-	 |
5  .....	 |
6  -....	 |
7  --...	 |
8  ---..	 |
9  ----.	 |

========================================================
 */

//Global Struct Variable for the Morse Codes.
Morse_Sym symbols[36] = {{".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"},{"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"},{"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {"-----"}, {".----"}, {"..---"}, {"...--"},{"....-"}, {"....."}, {"-...."}, {"--..."}, {"---.."}, {"----."}
};

//Global Variables
char morseCode[500] ="";

//Function to Convert the Given String into the Morse Codes
void convertMorse(char *str)
{
	int i=0,j=0;
	char c;
	while(*(str+i) != '\0'){
		c = *(str+i);
		if(c >= 'a' && c <= 'z'){
			strcat(morseCode, symbols[c-'a'].morse_sym);
			strcat(morseCode, " ");
		}
		else if(c >='A' && c <= 'Z'){
			strcat(morseCode, symbols[c-'A'].morse_sym);
			strcat(morseCode, " ");
		}
		else if(c >= '0' && c <= '9'){
			strcat(morseCode, symbols[c-'0' + 26].morse_sym);
			strcat(morseCode, " ");
		}
		else{
			strcat(morseCode, " ");
		}
		i++;
	}
	printf("\nConverted the Given String \"%s\" into Morse Code is \n%s\n",str, morseCode);
}

//Finction to Convert the Decoded Morse Code into the Readable Sentence.
void convertString(char *morse)
{
	int i=0,j=0,k=0,space=0,d=0, m;
	char conv[10], decoded[500];
	while(*(morse+i) != '\0'){
		if(*(morse+i) != ' '){
			conv[k++] = *(morse+i);
			space =0;
		}
		else{
			space++;
			if(k>0){
				conv[k] = '\0';
				for(m=0;m<36;m++){
					if(strcmp(conv, symbols[m].morse_sym)==0){
						if(m<26){
							decoded[d++] = 'a' + m;
						}
						else{
							decoded[d++] = '0' + (m-26);
						}
						break;
					}
				}
				k=0;
			}
			if(space == 2){
				decoded[d++] = ' ';
				/*while(*(morse+i) != '\0'){
					i++;
				}*/
				continue;
			}
		}
		i++;
	}
	if(k>0){
		conv[k] ='\0';
		for(m=0;m<36;m++){
			if(strcmp(conv,symbols[m].morse_sym)==0){
				if(m<26){
					decoded[d++] = 'a' + m;
				}
				else{
					decoded[d++] = '0' + 26;
				}
				break;
			}
		}
	}
	decoded[d] = '\0';
	printf("\nDecoded the Converted Morse Code into the Given string is \"%s\"\n", decoded);
}

//Main Starts Here
int main(){
	char inp_str[50];
	printf("\nEnter the String:\n");
	scanf("%49[^\n]s", inp_str);
	printf("\nGiven Input String is %s:", inp_str);
	convertMorse(inp_str);
	convertString(morseCode);
	return 0;
}
