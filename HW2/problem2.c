/*Michael Sarmento
HW2 part 2
10/12/19*/
#include <stdio.h>

//fucntions
void find_three_largest();
void total_count_of_three_largest(int num1, int num2, int num3);


int main()
{
	//call the function find_three_largest
	find_three_largest();
	return 0;


}

/*this function is used to find the three largest values from the input file*/
void find_three_largest()
{
	//variables
	int num1=0, num2=0, num3=0;
	int num =0;
	int first_largest,second_largest,third_largest;
	
	//open the file input.txt to read from
	FILE *fp;

	fp = fopen("input.txt", "r");

	//scan the first three integers values from the file and store them into different variables
	fscanf(fp,"%d", &num1);
	fscanf(fp,"%d", &num2);
	fscanf(fp,"%d", &num3);

	
	/*check if num1 is the greatest value*/
	if(num1 >num2 && num1 >num3)
	{
		first_largest = num1;
		/*check if num2 is the second greatest else it is the third greatest*/
		if(num2>num3)
		{
			second_largest = num2;
			third_largest= num3;
			 
		}else
		{
			second_largest = num3;
			third_largest= num2;
		}

	}

	/*check if num2 is the greatest value*/
	if(num2>num1 && num2>num3)
	{
		first_largest= num2;

		/*check if num1 is the second greatest value else it is the third greatest*/
		if(num1>num3)
		{
			second_largest= num1;
			third_largest = num3;
			 
		}else
		{
			second_largest = num3;
			third_largest = num1;
		}
	}
	
	/*check if num3 is the greatest value*/
	if(num3>num1 && num3>num2)
	{
		first_largest = num3;

		//check if num2 is the second greatest else it is the third greatest
		if(num2>num1)
		{
			second_largest = num2;
			third_largest = num1;
			 
		}else
		{
			second_largest = num1;
			third_largest = num2;
		}
	}

	//printf("%d %d %d",first_largest,second_largest,third_largest);


	/*use a for loop to scan through the remaining 17 integers in the file, check if the value scanned is
	greater than first, second or third greatest, if it is whatever value it is greater than say for instance second greatest,
	it would store it in second greatest and the orginal value of second greatest would be stored in third greatest */
	for(int i=0; i<17; i++)
	{
		
		fscanf(fp,"%d",&num);

		if(num>first_largest)
		{
			third_largest = second_largest;
			second_largest =first_largest;
			first_largest = num;
		}
		else if(num<first_largest&&num>second_largest)
		{
			third_largest =second_largest;
			second_largest = num;
		}
		else if(num>third_largest && num<second_largest)
		{
			third_largest = num;
		}


	}

	//call this function and pass first, second and third greatest by value through the function
	total_count_of_three_largest(first_largest,second_largest,third_largest);

	//printf("%d %d %d"\n,first_largest,second_largest,third_largest);

	//close file
	fclose(fp);

}


//this function is used to count the occurences of each of the three greatest values and print it out with the largest values
void total_count_of_three_largest(int num1, int num2, int num3)
{
	int count1 =0, count2 =0,count3 =0;
	int number;
	
	//open file
	FILE *fp;
	fp = fopen("input.txt", "r");

	//used to scan file and count total occurences of the values
	for(int i=0;i<20;i++)
	{
		fscanf(fp, "%d", &number);

		if(number == num1)
			count1++;
		if(number == num2)
			count2++;
		if(number == num3)
			count3++;


	}
	//print the three largest values with the total number of occurences
	printf("First largest digit: %d | Number of occurences: %d\n",num1,count1);
	printf("Second largest digit: %d | Number of occurences: %d\n",num2,count2);
	printf("Third largest digit: %d | Number of occurences: %d\n",num3,count3);

	//close file
	fclose(fp);

}