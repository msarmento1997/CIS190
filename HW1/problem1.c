/*Michael Sarmento
HW1 Part1
9/30/19*/


#include <stdio.h>

int main(void)
{
	/*Variables*/

	int num;
	int temp;
	int count=0;
	int count2;
	int power1=1;
	int power2;

	int i;
	int j;
	

	printf("Please enter a integer that ranges from 0 to 32984: ");
	scanf("%d",&num);

	/*check if user input matches requirements*/
	while(1)
	{
		if(num<0||num>32984)
		{
			printf("\nWrong user input. Please try again: ");
			scanf("%d",&num);

		}else
		{
			break;
		}

	}



	printf("\nUser Value: %d\n",num);
	
	temp = num;

	//get total digit count
	while(temp !=0)
	{
		temp/=10;
		count++;
	}

	
	//get the correct power of 10 to work with
	for(i=0;i<count;i++)
		power1*=10;

	power2=power1;

	//printf("%d\n",power1);
	
	
	count2=count;

	/*first loop creates the rows and second loop creates the columns*/

	for(i=0; i<=count+1;i++)
	{

		power1 = power2;
		
		for(j=0;j<=count2;j++)
		{
			/*print statement uses variable power which starts at one each time a new column is started and then it is multiplied by 10 each time to get
			number positions after you mod the result*/
			printf("%d   ",(num/power1)%10);
			power1 = power1 / 10;
		}
		
		printf("\n");
		
		//reduce count2 so less digits are printed after each row
		count2--;
		power2/=10;

	}

	//reinitializing values
	count2=count;
	power2=1;
	

	/*loop to print in reverse order*/
	for(i=0;i<=count+1;i++)
	{

		//if statements used to manipulate amount of spaces needed depending on n rows
		if(i==1)
			printf("    ");
		
		if(i==2)
			printf("        ");
		
		if(i==3)
			printf("            ");
		if(i==4)
			printf("                ");

		if(i==5)
			printf("                    ");
		if(i==6)
			printf("                        ");


		power1 = power2;
		for(j=0;j<=count2;j++)
		{
			printf("%d   ",(num/power1)%10);
			power1*=10;

		}

		printf("\n");

		//reduce count
		count2--;
		power2*=10;


	}


	return 0;

}