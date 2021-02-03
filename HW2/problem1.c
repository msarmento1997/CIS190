/*Michael Sarmento
HW2 part 1
10/12/19
*/
#include <stdio.h>
#include <math.h>

//functions
int calculate_A(int n);
int calculate_B(int n);
int calculate_D(int n);
void calculate_Y(double a, double b, double d);


int main(void)
{
	//vairables
	double a;
	double b;
	double d;

	int n;

	//scan user input
	printf("Please enter an integer value for n: ");
	scanf("%d",&n);

	//pass by value to functions to do calculations
	a = calculate_A(n);
	b = calculate_B(n);
	d= calculate_D(n);
	
	calculate_Y(a,b,d);

	return 0;

}


int calculate_A(int n)
{
	//variables 
	double num=0;
	double num2;
	int i;
	int j;

	//if n < 5 calculate the summation of n and then the product of that summation
	if(n<5)
	{
		num =1;
		for(i=1;i<=n; i++)
		{
			num2 =0;
			for(j=1;j<=i;j++)
			{
				
				
				num2 += j +1/i;
				//printf("inner loop: %lf\n",num2);
				
				
			}
			
			num *=num2;
			//printf("outer loop: %lf\n",num);
		}	
	}

	//if n is greater than or equal to 5 and less than 25 do the following summation arithmetic
	if(n>=5 && n<25)
	{
		for(i=1; i<=n;i++)
		{
			num = num + i + i*2;
		}
	}

	//if n is greater than or equal to 25 take the sqrt of n
	if(n >=25)
	{
		num = sqrt(n);
		
	}

	//return the value of what a will be
	return num;

}
//function to calculate b
int calculate_B(int n)
{
	//variable
	double num=0;
	
	//n is less than 5 take the sqrt of n
	if(n<5)
	{
		num = sqrt(n);
	}
	//n is greater than or equal to 5 and less than 25 do this math
	else if (n>=5 && n<25)
	{
		num= (n-1)*(n-2);
	}
	//take the celing value of n when n is between these bounds
	else if (n>=25 && n<45)
	{
		num = ceil(n);
	}else
	{
		num = n;// if n is greater than greater than or equal to 45 return n
	}

	//return num which is the value of b
	return num;
}

//function that calculates the value of d
int calculate_D(int n)
{
	//variable
	double num=0;

	//switch statement 
	switch(n)
	{
		//when n is 1 or 2 it will perfrom the same type of arithemetic 
		case 1:
			num = n +sin(n);
			break;
		case 2:
			num = n + sin(n);
			break;
		//when n is between 3 - 5 it will perfrom the same arithemetic
		case 3:
			num = n-3;
			break;
		case 4:
			num = n-3;
			break;
		case 5:
			num = n-3;
			break;
		//when n is any value besides 1-5 it will perfrom this arithemetic
		default:
			num = n*2;
	}

	//return the value of d
	return num;




}

//function used to calculate the value of y and print to user
void calculate_Y(double a, double b, double d)
{
	//variables
	double y=0;
	double half = .5;
	//math done to caluclate y
	y= a+b - half *d;

	
	//print the answers and numbers used to calculate the answer
	printf("y = a + b - 1/2 * d\n");
	printf("%lf = %lf + %lf - 1/2 * %lf\n",y,a,b,d);
	printf("Value of y: %lf\n",y);

}