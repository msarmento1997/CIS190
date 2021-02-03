#include <stdio.h>
#include <string.h>

#define BUFFER 512

int count_character(char character, char string[], int count, int i);

int main()
{
	char string[BUFFER];
	char character;
	int count =0;
	int i=0;

	printf("Enter a string: ");
	fgets(string, sizeof(string), stdin);

	printf("\nPlease enter a character you want to count: ");
	character=getchar();

	printf("%d\n",count_character(character,string, count,i));

}



int count_character(char character, char string[], int count, int i)
{
	if(i== strlen(string))
	{
		
		return count;

	}
	else if(character == string[i])
	{
		count++;
		count_character(character,string,count,i+1);
	}
	else
		count_character(character, string,count,i+1);



}