/*Michael Sarmento
CIS 190 HW3 problem1
11/01/19*/

/*C program for Tower of Hanoi using recursion*/

#include <stdio.h>

void towers(int, char, char, char);

int main()
{
	int num;
	printf("Enter the number of disks : ");
	scanf("%d",&num);
	printf("The sequence of moves involved in the Tower of Haha are : \n\n");
	towers(num, 'A', 'B', 'C');
	/*changed this line by replacing the position from A,C,B to A,B,C
	reason being it A is the starting peg, B is the peg that you want everything to move to, C is the peg that is used 
	to move disks from A to B*/
	return 0;
}

void towers(int num, char frompeg, char topeg, char auxpeg)
{

	if(num == 1)
	{
		printf("Move disk 1 (red) from peg %c to peg %c\n", frompeg, topeg);
		return;
	}
	towers(num-1, frompeg, auxpeg, topeg);
	//printf("\nMove disk %d from peg %c to peg %c", num, frompeg, topeg);
	//this will print the disks movement and also whether it is a red or yellow disk (even or odd).
	if(num%2 == 1)
	{
		printf("Move disk %d (red) from peg %c to peg %c\n", num, frompeg, topeg);
	}
	else if(num%2 == 0)
	{
		printf("Move disk %d (yellow) from peg %c to peg %c\n", num, frompeg, topeg);
	}
	towers(num-1,auxpeg, topeg,frompeg);
}
