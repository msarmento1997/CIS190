/*Michael Sarmento
HW5 problem 1
11/27/19*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 5
#define COLUMN 5

int randomNumber(int min, int max);
int fillColumns(int bingoCard[ROW][COLUMN],int bingoCard1[ROW][COLUMN],int bingoCard2[ROW][COLUMN]);
void printBingoCard(int bingoCard[ROW][COLUMN]);
int checkForWin(int bingoCard[ROW][COLUMN],int numbers[75]);
int numbersDrawn(int numbers[75]);


int main()
{
	//bingo card array for 3 players
	int bingoCard[ROW][COLUMN]={0};
	int bingoCard1[ROW][COLUMN]={0};
	int bingoCard2[ROW][COLUMN]={0};

	//holds the count of how many numbers were drawn until a player hit bingo
	int count1;
	int count2;
	int count3;

	//tells which person was a winner
	int win=0;

	//array holds the random numbers drawn
	int numbers[75]={0};
	
	srand(time(NULL));

	//function call to fill bingocards and make sure no bingocard is similar to another players
	printf("We are going to play bingo now, the three players Bingo Cards will be generated at this time.\n\n");
	fillColumns(bingoCard,bingoCard1,bingoCard2);
  	fillColumns(bingoCard1,bingoCard,bingoCard2);
  	fillColumns(bingoCard2,bingoCard,bingoCard1);

  	  //print each players randomized board
	  printf("\nPlayer1 Board\n\n");
	  printBingoCard(bingoCard);
	  printf("\nPlayer2 Board\n\n");
	  printBingoCard(bingoCard1);
	  printf("\nPlayer3 Board\n\n");
	  printBingoCard(bingoCard2);

	  //fill the array of numbers to show the order of numbers drawn in order to play bingo
	  numbersDrawn(numbers);

	  //check which player won and return the count.
	  count1=checkForWin(bingoCard,numbers);
	  count2=checkForWin(bingoCard1,numbers);
	  count3=checkForWin(bingoCard2,numbers);

	  
	  //compare count for each player, which ever person has a smaller count is the winner, except if the count is -1 that means the player never won
	  if(count1<count2 && count1<count3)
	  {
	  	if(count1 !=-1)
	  	{
	  		printf("\nPlayer 1 wins\n");
	  		win=1;
	  	}
	  }
	  if(count2<count1 && count2<count3)
	  {
	  	if(count2 !=-1)
	  	{
	  		printf("\nPlayer 2 wins\n");
	  		win =1;	
	  	}
	  }
	  if(count3<count1 && count3<count2)
	  {
	  	if(count3 !=-1)
	  	{
	  		printf("\nPlayer 3 wins\n");
	  		win =1;
	  	}
	  }

	  /*this check if there is a tie between players, either a two-way tie or three-way tie
	  though this case is a little rare it is still possible and i've come across a two way tie a few times in my testing, however I havent
	  come across a three way tie in my testing, but its best to keep the condition just in case of that probability of it happening*/
	  if(win !=1)
	  {
		  if(count1 == count2 && count1 == count3)
		  {
		  	printf("\nThree way Bingo\n");
		  }
		  if(count1 == count2)
		  {
		  	printf("\nBingo tie between Player 1 and Player 2\n");
		  }
		  if(count1 == count3)
		  {
		  	printf("\nBingo tie between Player 1 and Player 3\n");
		  }
		   if(count3 == count2)
		  {
		  	printf("\nBingo tie between Player 2 and Player 3\n");
		  }
	  }

	  return 0;


}


//check for win 
int checkForWin(int bingoCard[ROW][COLUMN], int numbers[75])
{
	//variables
	int i,j,k,l;
	int win=0;
	int count=0;

	//first loop is to draw a new number from the array of numbers
	for(i=0;i<75;i++)
	{
		//this loop is to check for rows on bingo card
		for(j=0;j<ROW;j++)
		{
			//this loop checks for columns on bingo card
			for(k=0;k<COLUMN;k++)
			{
				/*if the position on bingo card is equal to the number drawn then we will set that position to 0, that way we are able to check 
				if there are 5 0's in a row, column, or diagonal for a win*/
				if(bingoCard[j][k] == numbers[i])
				{
					bingoCard[j][k]=0;
					count++;
					//check rows for winner
					for(l=0;l<ROW;l++)
					{
						if(bingoCard[l][0]==0&&bingoCard[l][1]==0&&bingoCard[l][2]==0&&bingoCard[l][3]==0&&bingoCard[l][4]==0)
						{
							win=1;
							break;
						}
					}

					//check colums for winner
					for(l-0;l<COLUMN;l++)
					{
						if(bingoCard[0][l]==0&&bingoCard[1][l]==0&&bingoCard[2][l]==0&&bingoCard[3][l]==0&&bingoCard[4][l]==0)
						{
							win=1;
							break;
						}
					}

					//check diagonals for winner
					
					if(bingoCard[0][0]==0&&bingoCard[1][1]==0&&bingoCard[2][2]==0&&bingoCard[3][3]==0&&bingoCard[4][4]==0)
					{
						win=1;
						break;
					}
					if(bingoCard[0][4]==0&&bingoCard[1][3]==0&&bingoCard[2][2]==0&&bingoCard[3][1]==0&&bingoCard[4][0]==0)
					{
						win=1;
						break;
					}

					//check if there is a win, if so return count, if not return -1
					if(win==1)
					{
						return count;
					}
					else if(i==74)
					{
						return -1;
					}

				}


				
			}
		}
	}
	
}

//function used to randomly draw 75 numbers that dont repeat from 1-75
int numbersDrawn(int numbers[75])
{
	int i,j;
	int num;

	for(i=0;i<75;i++)
	{
		num=randomNumber(1,75);

		if(i==0)
		{
			numbers[i]=num;
		}
		if(i>0)
		{
			j=0;

			while(1)
			{
				if(numbers[j]==num)
				{
					j=0;
					num=randomNumber(1,75);
				}
				else if(j==i)
				{
					numbers[i]=num;
					break;
				}
				j++;

			}	
		}
	}
}

//generates random numbers between a certain range 
int randomNumber(int min, int max)
{
    return min + (rand() % (max - min + 1));
}


//function to fill each column and make sure no numbers repeat accross all three player boards
int fillColumns(int bingoCard[ROW][COLUMN],int bingoCard1[ROW][COLUMN],int bingoCard2[ROW][COLUMN])
{
    //declared variables
    int num;
    int correct =1;
    int i;

    //for loop to check first column and fill them with random generated numbers
    for(i=0;i<ROW;i++)
    {
        //call random number and store it into num
        num=randomNumber(1,15);

        //loop which makes sure before the random number is stored in the array must be compared to the other boards to make sure there is no repeating
        do{
            if(num!=bingoCard[0][0]&&num!=bingoCard[1][0]&&num!=bingoCard[2][0]&&num!=bingoCard[3][0]&&num!=bingoCard[4][0]&&num!=bingoCard1[0][0]&&
            num!=bingoCard1[1][0]&&num!=bingoCard1[2][0]&&num!=bingoCard1[3][0]&&num!=bingoCard1[4][0]&&num!=bingoCard2[0][0]&&
            num!=bingoCard2[1][0]&&num!=bingoCard2[2][0]&&num!=bingoCard2[3][0]&&num!=bingoCard2[4][0])
            {
                bingoCard[i][0]=num;
                correct=1;
            }else
            {
              num=randomNumber(1,15);
              correct=0;
            }
          }while(correct!=1);


    }

    int correct2=1;

    //for loop to check the second column column of the board and fill it with random generated numbers
    for(i=0;i<ROW;i++)
    {
        num=randomNumber(16,30);

        do{
            if(num!=bingoCard[0][1]&&num!=bingoCard[1][1]&&num!=bingoCard[2][1]&&num!=bingoCard[3][1]&&num!=bingoCard[4][1]&&num!=bingoCard1[0][1]&&
            num!=bingoCard1[1][1]&&num!=bingoCard1[2][1]&&num!=bingoCard1[3][1]&&num!=bingoCard1[4][1]&&num!=bingoCard2[0][1]&&
            num!=bingoCard2[1][1]&&num!=bingoCard2[2][1]&&num!=bingoCard2[3][1]&&num!=bingoCard2[4][1])
            {
                bingoCard[i][1]=num;
                correct2=1;
            }else
            {
              num=randomNumber(16,30);
              correct2=0;
            }
          }while(correct2!=1);


    }

    int correct3=1;
    //for loop to check the third column column of the board and fill it with random generated numbers
    for(i=0;i<ROW;i++)
    {
        num=randomNumber(31,45);

        do{
            if(num!=bingoCard[0][2]&&num!=bingoCard[1][2]&&num!=bingoCard[2][2]&&num!=bingoCard[3][2]&&num!=bingoCard[4][2]&&num!=bingoCard1[0][2]&&
            num!=bingoCard1[1][2]&&num!=bingoCard1[2][2]&&num!=bingoCard1[3][2]&&num!=bingoCard1[4][2]&&num!=bingoCard2[0][2]&&
            num!=bingoCard2[1][2]&&num!=bingoCard2[2][2]&&num!=bingoCard2[3][2]&&num!=bingoCard2[4][2])
            {
                bingoCard[i][2]=num;
                correct3=1;
            }else
            {
              num=randomNumber(31,45);
              correct3=0;
            }
          }while(correct3!=1);


    }

    int correct4=1;
    //for loop to check the fourth column column of the board and fill it with random generated numbers
    for(i=0;i<ROW;i++)
    {
        num=randomNumber(46,60);

        do{
            if(num!=bingoCard[0][3]&&num!=bingoCard[1][3]&&num!=bingoCard[2][3]&&num!=bingoCard[3][3]&&num!=bingoCard[4][3]&&num!=bingoCard1[0][3]&&
            num!=bingoCard1[1][3]&&num!=bingoCard1[2][3]&&num!=bingoCard1[3][3]&&num!=bingoCard1[4][3]&&num!=bingoCard2[0][3]&&
            num!=bingoCard2[1][3]&&num!=bingoCard2[2][3]&&num!=bingoCard2[3][3]&&num!=bingoCard2[4][3])
            {
                bingoCard[i][3]=num;
                correct4=1;
            }else
            {
              num=randomNumber(46,60);
              correct4=0;
            }
          }while(correct4!=1);


    }
    int correct5=1;
    //for loop to check the fifth column column of the board and fill it with random generated numbers
    for(int i=0;i<ROW;i++)
    {
        num=randomNumber(61,75);

        do{
            if(num!=bingoCard[0][4]&&num!=bingoCard[1][4]&&num!=bingoCard[2][4]&&num!=bingoCard[3][4]&&num!=bingoCard[4][4]&&num!=bingoCard1[0][4]&&
            num!=bingoCard1[1][4]&&num!=bingoCard1[2][4]&&num!=bingoCard1[3][4]&&num!=bingoCard1[4][4]&&num!=bingoCard2[0][4]&&
            num!=bingoCard2[1][4]&&num!=bingoCard2[2][4]&&num!=bingoCard2[3][4]&&num!=bingoCard2[4][4])
            {
                bingoCard[i][4]=num;
                correct5=1;
            }else
            {
              num=randomNumber(61,75);
              correct5=0;
            }
          }while(correct5!=1);


    }

}


//prints the bingo card to the user
void printBingoCard(int bingoCard[ROW][COLUMN])
{

    int i;
    int j;

    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COLUMN;j++)
        {
            if(i==2&&j==2)
            {
                printf("FREE\t");
            }else
            {
              printf("%d\t",bingoCard[i][j]);
            }
        }
        printf("\n\n");

    }



}