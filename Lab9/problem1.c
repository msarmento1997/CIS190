/*

Michael Sarmento

CIS 190

11/6/19

Lab 9: Malloc & Realloc

*/



#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define BUFFER 256



//Predefined Functions:
void getInput(int *quit, int **integers, int *intCount, double **doubles, int *doubleCount, char **characters, int *charCount, char ***stringPtrs, int *stringCount);
int validateType(char string[BUFFER]);
void printArrays(int **integers, int *intCount, double **doubles, int *doubleCount, char **characters, int *charCount, char ***stringPtrs, int *stringCount);


int main(void)
{

	//Array for each type:

	char **stringPtrs = malloc(sizeof(char*)); //Array of char pointers for strings
	int *integers = malloc(sizeof(int));
	double *doubles = malloc(sizeof(double));
	char *characters = malloc(sizeof(char));



	//Integers to keep counts of each type:
	int stringCount = 0, intCount = 0, doubleCount = 0, charCount = 0;

	

	printf("Press enter to quit.\n");
	int quit = 0;
	do{
		getInput(&quit, &integers, &intCount, &doubles, &doubleCount, &characters, &charCount, &stringPtrs, &stringCount);
		if(quit == 1) //Break if quit is one so we don't print the list again.
			break;
		printArrays(&integers, &intCount, &doubles, &doubleCount, &characters, &charCount, &stringPtrs, &stringCount); //print arrays using our arrays in main
		printf("\n");
	}while(quit == 0); //continue getting input until quit is 1.

	//Free the memory after done:
	int i;
	for(i = 0; i < stringCount; i++)
		free(stringPtrs[i]); //free each individual string
	
	//free each array pointer:
	free(stringPtrs);
	free(integers);
	free(doubles);
	free(characters);
	printf("Memory has been freed.\n");
	return 0;
}



//Gets user input and adds the input to the proper array:

void getInput(int *quit, int **integers, int *intCount, double **doubles, int *doubleCount, char **characters, int *charCount, char ***stringPtrs, int *stringCount)
{
	char string[BUFFER] = {0}; //Create string thats buffer length (256)
	printf("Enter your input: ");
	fgets(string,BUFFER,stdin); //get the user's input
	string[strlen(string) - 1] = 0; //Fixes array size for string.

	printf("\n"); //Print line for spacing.


	switch(validateType(string))
	{
		case 1: //Char
			(*charCount)++; //Increment char count.
			(*characters) = realloc(*characters, (*charCount) * sizeof(char));
			sscanf(string,"%c",&(*characters)[(*charCount) - 1]);
			break;

		case 2: //Integer
			(*intCount)++; //Increment the integer count
			(*integers) = realloc(*integers, (*intCount) * sizeof(int));
			sscanf(string,"%d", &(*integers)[(*intCount) - 1]); //Scan the integer to the address of the next int
			break;

		case 3: //Double
			(*doubleCount)++; //Increment double count
			(*doubles) = realloc(*doubles, (*doubleCount) * sizeof(double)); //Reallocate for one more double
			sscanf(string, "%lf", &(*doubles)[(*doubleCount) - 1]); //Scan the new double from string to the address of the newest double
			break;

		case 4:	//String
			(*stringCount)++; //Increment string count
			(*stringPtrs) = realloc((*stringPtrs), (*stringCount) * sizeof(char*)); //Reallocate memory for one more char pointer
			(*stringPtrs)[(*stringCount)-1] = calloc(strlen(string), sizeof(char)); //Create memory for the string and set it to the next pointer.
			strcpy((*stringPtrs)[(*stringCount)-1],string); //Copy the string to the new pointer.
			break;

		case 5:
			printf("Quitting...\n");
			*quit = 1;
			break;

	}	
}



//Print out each array:

void printArrays(int **integers, int *intCount, double **doubles, int *doubleCount, char **characters, int *charCount, char ***stringPtrs, int *stringCount)
{	
	int i;
	//print each string in the stringptr array:
	printf("String list: ");
	for(i = 0; i < (*stringCount); i++)
		printf("%s ",(*stringPtrs)[i]);

	printf("\n");

	//Print each integer in the array:
	printf("Integer list: ");
	for(i = 0; i < (*intCount); i++)
		printf("%d ", (*integers)[i]);

	printf("\n");

	//Print each double in the arraY:
	printf("Double list: ");
	for(i = 0; i < (*doubleCount); i++)
		printf("%.1lf ", (*doubles)[i]);

	printf("\n");

	//Print each character in the list:
	printf("Character list: ");
	for(i = 0; i < (*charCount); i++)
		printf("%c ", (*characters)[i]);

	printf("\n");

}





//Return what type the inputtded string is:

//1 = Char, 2 = Int, 3 = Double, 4 = String, 5 = Empty

int validateType(char string[BUFFER])
{

	//If string is only one long (char or int):



	if(strlen(string) == 0) //If empty, return 5:

		return 5;



	if(strlen(string) == 1) //if only 1 long

	{

		if(string[0] >= '0' && string[0] <= '9'){

			return 2; //If it's a digit, return integer

		}else{

			return 1; //if not a digit then it's a char

		}

	}else{

		int i=0, decp = 0, into = 0;

		//If the first character is a negative sign: set the 

		if(string[0] == '-')

			i = 1;

		//See if only digits:

		for(; i < strlen(string); i++)

		{	

			if(string[i] == '.') //If decimal point, increment decp

				decp++;

			else if((string[i] < '0' || string[i] > '9')) //If it's not a decimal, and not a digit, then increment into

					into++; 

		}

		//If it contains 1 Decimal place and is only integers, then it's a double:

		if(decp == 1 && into == 0)

			return 3;

		else

		{	//If its not a double:
			if(decp > 1) //IF more then one decimal it's a string:
				return 4;



			if(into == 0)	//If only digits it's a integer.

				return 2;



			return 4;	//If not any of the above then just default to string.

		}

	}

}

