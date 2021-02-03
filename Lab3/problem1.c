/*Michael Sarmento
9/18/19
Lab3*/

#include <stdio.h>

int main(void){

	/*variables*/
	int num;
	int first;
	int second;
	int third;
	int fourth;
	int fifth;

	/*ask user for input*/
	printf("Please enter a integer that ranges from 0 to 32,767: ");
	scanf("%d",&num);

	/*make sure correct input is entered*/
	while(1)
	{
		if(num<0||num>32767)
		{
			printf("\nWrong user input. Please try again.: ");
			scanf("%d",&num);
		}else
		{
			break;
		}

	}

	/*break number entered by user to specific digits*/
	fifth = num%10;
	fourth = ((num/10)%10);
	third = ((num/100)%10);
	second = ((num/1000)%10);
	first = ((num/10000)%10);

	/*Write output to a file with correct formatting*/
	FILE *output;
	output = fopen("output.txt", "w");

	fprintf(output, "%d   %d   %d   %d   %d\n",first,second,third,fourth,fifth);
	fprintf(output, "  %d   %d   %d   %d\n",second,third,fourth,fifth);
	fprintf(output, "    %d   %d   %d\n",third,fourth,fifth);
	fprintf(output, "      %d   %d\n",fourth,fifth);
	fprintf(output, "        %d\n",fifth);

	fclose(output);

	return 0;
}
