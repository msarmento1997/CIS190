/*Michael Sarmento
 10/2/19
 Lab 5 part 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printCardName(int drawn);
int drawCard();
int getCardValue();
int determineWinner(int dealer, int player);
void playGame();
int input(); //PUT YOUR INPUT TYPE HERE

int main(){
	//only call playGame here
	srand(time(NULL));//Set seed for the program:

	playGame(); // call playgame function
	return 0;
}

//play the game here
void playGame(){
	//put game inside a while loop, only exiting when a player is done
	//put logic for the players turn,the dealers turn, and determining winner and if they player wishes to play again here, using apporpriate functions
	int playGame = 1;

	do{
			int totalPlayerCard = 0;
			int totalDealerCard = 0;
			int card1;
			int card2;
			int firstWin = 0;

			card1 = drawCard();//draw first card

			if(card1==1){
				card2 = drawCard();//draw a second card

						if(card2 == 10|| card2 == 11 || card2 == 12 || card2 == 13)//if the second card is a 10,jack, queen, or king
						{
								firstWin=1;

						}

			}else if(card1 == 10 || card1 == 11 || card1 == 12 || card1 == 13 )//if the first card drawn is a 10, jack, queen, or king
				{
					card2 = drawCard();

							if(card2==1)
							{
								firstWin = 1;
							}
				}else
						{
							card2 = drawCard();// draw a card if the first card isn't a 10, jack, queen, king, or ace
						}

			//if the play didnt get 21 during the first draw of their 2 cards
			if(firstWin == 0){

				totalPlayerCard = getCardValue(card1) + getCardValue(card2);//gets total value of cards

				printf("Player drew a ");//prints first card
				printCardName(card1);

				printf("Player drew a ");//prints second card
				printCardName(card2);

				printf("Player started with a total of: %d\n", totalPlayerCard);//prints the total of the cards


				int userValue = 0;

				do{
						printf("Player current card value total: %d\n", totalPlayerCard);
						printf("Draw another card or stay at current total (0 = no, 1 = yes)?\n");//ask if the user wants to draw another card or not
						userValue = input();//if user puts 1 then they draw another card otherwise they stay

						while(userValue !=0 && userValue !=1)//do this loop if user enters anything other than a 1 or 0
						{
							printf("Error! Please enter either a 1 or 0\n");

							getchar();

							userValue = input();
						}

						if(userValue==1)//draw a new card
						{
							int card = drawCard();

							printf("\nNew Card Drawn: ");
							printCardName(card);//print name of the new card

							if(card==1)//if card drawn is an ace
							{
									int userValue2;//for new user userValue

									printf("You drew an Ace. Do you want its value to be either a 1 or 11?\n");

									userValue2 = input();


									while(userValue2 !=1 && userValue2 !=11)//to make sure user enters 1 or 11
									{
											printf("Error! Please enter either a 1 or 11\n");

											getchar();

											userValue2 = input();//get new value for ace


									}

									totalPlayerCard +=userValue2;

							}else{

										totalPlayerCard +=getCardValue(card);
								}


						}

						if(totalPlayerCard>=21)//break loop if player card total is 21 or over
						{
							break;
						}


				}while(userValue == 1);

				if(totalPlayerCard>21)
				{
					printf("Player went over 21. You lost\n");//if player goes over 21 then print that they lost
				}else
				{

					//Draw dealer's cards until > total play car value



					do{

						int card = drawCard(); //draw new card for dealer

						printf("Dealer drew a ");

						//add the correct card value to the deck:

						totalDealerCard+=getCardValue(card);

						printCardName(card); //Print the name of the card

						if(card==1 && totalDealerCard>10)
						{

								totalDealerCard+=1;
						}


					} while(totalDealerCard < totalPlayerCard);

					if(totalDealerCard > 21)//to check if dealer went over 21
					{
						 printf("Player won! Dealer went over 21\n");
					}else
					{
						switch(determineWinner(totalDealerCard,totalPlayerCard))//determine who won the game
						{
								case 0:	printf("Dealer won the hand.\n");
									break;
								case 1: printf("Player won the hand.\n");
									break;
								case 2: printf("The hand was a tie.\n");
									break;

						}

					}
					//Print the totals of the hand for the player and dealer
					printf("Player's hand total:%d\tDealer's hand total:%d\n",totalPlayerCard,totalDealerCard);

				}

			}else{
				printf("Player won on the first draw\n");
			}

			printf("Would you like to play another hand(0 = no, 1 = yes)?\n");

			playGame = input();

			while(playGame !=0 && playGame !=1)
			{
					printf("Error! Please enter either a 1 or 0\n");
					playGame = input();

			}

	}while(playGame == 1);


	return;
}

//draw a card here
int drawCard(){

	//Generate a number between 1 and 13
	int drawnCard = rand() % ((13+1)-1)+1;

	return drawnCard;
}

//get cards correct value
int getCardValue(int card){

	if(card == 1) //If card is an ace

	{

		return 11; //return 11

	} else if(card == 11 || card == 12 || card == 13) { //if card is a face card

		return 10;

	} else

		return card; //return the face value of normal cards

}

//print the cards name that you drew
void printCardName(int drawn){
	//use a switch statement to determine the card name

	switch(drawn)

	{

	case 1:printf("Ace\n");
		break;

	case 2:printf("%d\n",drawn);
		break;

	case 3:printf("%d\n",drawn);
		break;

	case 4:printf("%d\n",drawn);
		break;

	case 5:printf("%d\n",drawn);
		break;

	case 6:printf("%d\n",drawn);
		break;

	case 7:printf("%d\n",drawn);
		break;

	case 8:printf("%d\n",drawn);
		break;

	case 9:printf("%d\n",drawn);
		break;

	case 10:printf("%d\n",drawn);
		break;

	case 11:printf("Jack\n");
		break;

	case 12:printf("Queen\n");
		break;

	case 13:printf("King\n");
		break;

	}

	return;
}

//determine the winner here, remembering that C does not have booleans
int determineWinner(int dealer, int player){

	if(dealer > player){ //Dealer won

		return 0;

	}else if(player > dealer){ //Player won

		return 1;

	}else if(player == dealer){ //Tie

		return 2;

	}else{
		return 3;
	}
}

//get player input here
//REPLACE (your Input type here) WITH WHAT KIND OF INPUT YOU WISH TO USE
int input(){
	int playerInput; //Declare playerInput integer

	scanf("%d",&playerInput); //Scan the input

	return playerInput;
}
