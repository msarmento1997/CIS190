/*Michael Sarmento
CIS 190 HW3 Problem2
11/01/19*/

#include <stdio.h>


void quicksort(int array[],int n);
int racks(int arr[], int length, int n, int count, int index, int rack); 

int main()
{

	//array containing sizes needs for racks
	int array[]={4,3,4,1,7,8};

	//size of array
	int n = sizeof(array)/sizeof(array[0]);

	//stock length of racks
	int length=10;

	//initialize variables
	int rack=1;

	int index=0;

	int count=0;
	
	/*if size of array is greater than 0 continue to find number of pipes needed*/
	if(n >0)
	{
		//quicksort function used to sort array in descending order
		quicksort(array, n);
		racks(array, length, n, count, index, rack);//racks functions used to recursively find minimum number of racks
	}else
	{
		printf("There are 0 Racks needed\n");
	}

}

//iterative quicksort function used to sort the array of rack sizes in descending order
void quicksort(int array[], int n)
{
	
	int i,j;
	int temp;

	for(i=0; i<n; ++i)
	{
		for(j=i+1; j<n; ++j)
		{
			if(array[i] < array[j])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}

}

//racks function used to determine number of stock racks needed and how the rack sizes should be dispersed 
int racks(int array[], int length, int n, int count, int index, int rack)
{
	int sum, i;

	//check if count is not equal to n(size of array)
	if(count != n)
	{
		//for loop to look for first value in array
		for(i=0;i<n;i++)
		{
			//if the value of array[i] is not equal to 0 then store the value in sum
			if(array[i] !=0)
			{
				sum = array[i];
				index =i;// index equals position of i
				i = length;//i equals length of stock rack
			}
		}
		array[index] = 0;//store index used of array as 0
		count++;

		//print rack number and print sum which is first array used each time in loop
		printf("Rack %d: %d ", rack, sum);

		//loop used to find next values to be associated with rack
		for(i=0;i<n;i++)
		{	//checks if value is greater than 0
			if(array[i]>0)
			{	
				//checks if the new value +sum is less than or equal to length, if so that value will be used for the current rack
				if(sum + array[i]<=length)
				{
					sum += array[i];
					printf("%d ",array[i]);
					array[i] = 0;
					count++;
				}
			}
		}
		printf("\n");
		//recursive fucntion call to return index+1 and to return the new count of rack
		racks(array, length, n, count, index+1, rack+1);
	}
}
