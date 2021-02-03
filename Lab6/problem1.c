/*Michael Sarmento
Lab6
10/9/19*/
#include <stdio.h>
int countBits(int num);// returns the number of “on”bits in an integer
int reverseBits(int num); // returns an int with reverse bits of an integer
int isEven(int num); // returns 1 if num is even, 0 otherwise
void printBinary(int num);// takes an integer and prints it in binary

int main(void)
{
	
	int num;
	
	printf("Enter an integer: ");

	scanf("%d", &num);

	printf(" NUmber (Binary): ");
	printBinary(num);
	printf("\n");

	int numBits = countBits(num);

	int revNum = reverseBits(num);

	int isEvn = isEven(num);

	printf("Number of 'on' bits %d\n", numBits);

	printf("Reversed number: %d\n", revNum);

	printf("Reversed number (binary): ");
	
	printBinary(revNum);
	
	printf("\n");


	printf("The number is %seven\n", isEvn?"":"not ");


}


int countBits(int num)
{
	//int count = 0;
	
	for(int count =0; num;)
	{
		count +=num&1;
		num>>=1;
		if(num ==0)
			return count;
	}
	/*while(num)
	{
		count +=num&1;
		num>>=1;
	}

	return count;*/




}
int reverseBits(int num)
{
	int rev =0;
	while(num>0)
	{
		rev<<=1;
		if(num&1 == 1)
		{
			rev ^=1;
		}
		num>>=1;
	}
	return rev;


}


int isEven(int num)
{
	if(num &1)
	{
		return 0;
	}
	else 
		return 1;
}

void printBinary(int num)
{
	
	printf("0b");

	for(int i=31, k; i>=0; i--)
	{
		
		if((k=num>>i)&1)
		{
			printf("1");
		}
		else if(i<=9)
		{
			printf("0");
		}
		
		
	}



}
