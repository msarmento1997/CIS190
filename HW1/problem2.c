/*Michael Sarmento
HW1 part2
9/30/19*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	/*Local variables*/
	int random_number;
	int random1;
	int random2;
	int random3;
	int user_guess;
	int digit1;
	int digit2;
	int digit3;
	int max_guesses = 10;
	int i;
	int win = 0;



	srand(time(NULL));
	//generating 3 digit random number
	random_number = (rand() % 900 +100);

	//printf("%d\n",random_number);


	/*Store each digit of random number into a variable. Also make sure that each digit is unique... no repeating digits*/
	while(1)
	{
		random1 = (random_number/100)%10;
		random2 = (random_number/10)%10;
		random3 = random_number % 10;

		if((random1 != random2) && (random1 != random3) && (random2 !=random3))
			break;
		else
			random_number = (rand()%900 +100);


	}

	//printf("%d\n",random_number);


	/*loop where game is played for up to 10 tries*/
	for(i=0; i<max_guesses; i++)
	{

		//ask for user input
		printf("This is your number %d guess\n",i+1);
		printf("What is your 3 digit guess: ");
		scanf("%d",&user_guess);

		while(1)
		{
			if(user_guess<100 || user_guess>999)
			{
				printf("Invalid input! Please enter an integer from 100 to 999: ");
				scanf("%d",&user_guess);

			}
			else
				break;

		}



		digit1 = (user_guess/100)%10;
		digit2 = (user_guess/10)%10;
		digit3 = user_guess%10;


		//check if user input had any digits that matched the random number
		if((digit1 == random2) || (digit1 == random3))
			printf("%d is a match\n",digit1);
		if((digit2 == random1) || (digit2 == random3))
			printf("%d is a match\n",digit2);
		if((digit3 == random1) || (digit3 == random2))
			printf("%d is a match\n", digit3);


		//check if user input had any digits that was a hit in the same digit position as random number
		if(digit1 == random1)
			printf("%d is a hit\n",digit1);
		if(digit2 == random2)
			printf("%d is a hit\n", digit2);
		if(digit3 == random3)
			printf("%d is a hit\n", digit3);


		//check if the user guessed the number correctly
		if((digit1 == random1) && (digit2 == random2) && (digit3 == random3))
		{
			printf("\nCongratulations! You correctly guessed %d\n", random_number);
			break;
			win = 1;
		}
		



	}


	//if user lost
	if(win !=1)
		printf("\nSorry you ran out of guesses the correct number is %d\n",random_number);



	return 0;


}