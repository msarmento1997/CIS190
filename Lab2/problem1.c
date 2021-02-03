/*Michael Sarmento
Lab2
9/11/19
*/
#include <stdlib.h>
#include <stdio.h>

/*constants*/
#define JAGUAR 249.00
#define REMOTE 49.59
#define CDI 1000.00
#define DO 699.99
#define BETAMAX 1300.00
int main(){
	
	
	
	/*variables to calculates cost of each item*/
	float cost1;
	float cost2;
	float cost3;
	float cost4;	
	float cost5;
	
	/*varaibles for taxes, subTotal and total cost*/
	float tax = .0525;
	float subTotal;
	float total;
	float tax1;	
	
	/*users inputs get stored in these variables*/
	int _jags;
	int _cdi;
	int _rem;
	int _3DO;
	int _betamax;


	
	
	/*print and scan users imputs for each item*/
	printf("How many Jaguars were sold?:");
	scanf("%d", &_jags);

	printf("How many CDi's were sold?:");
	scanf("%d", &_cdi);
	
	printf("How many remotes were sold?:");
	scanf("%d", &_rem); 
	
	printf("How many 3DO's were sold?:");
	scanf("%d", &_3DO); 
	
	printf("How many betamax's were sold?:");
	scanf("%d", &_betamax); 

	/*calculates costs of each item*/
	cost1 = JAGUAR * _jags;
	cost2 = REMOTE * _rem;
	cost3 = CDI * _cdi;
	cost4 = DO * _3DO;
	cost5 = BETAMAX * _betamax;


	/*calculates subtotal and total cost after taxes*/
	subTotal = cost1 + cost2 + cost3 + cost4 + cost5;
	tax1 = subTotal * tax;
	total = (subTotal * tax)+subTotal;
	
	/*prints out a breakdown list of each cost to the user*/
	printf("QTY\tDESCRIPTION\tUNIT PRICE\tTOTAL PRICE\n");
	printf("___\t____________\t__________\t__________\n");
	printf("%d\tJAGUAR\t\t%7.2f\t\t%7.2f\n",_jags,JAGUAR,cost1);
	printf("%d\tCDI\t\t%7.2f\t\t%7.2f\n",_cdi,CDI,cost3);
	printf("%d\tREMOTE CTRLR\t%7.2f\t\t%7.2f\n",_rem,REMOTE,cost2);
	printf("%d\t3DO\t\t%7.2f\t\t%7.2f\n",_3DO,DO,cost4);
	printf("%d\tBETAMAX\t\t%7.2f\t\t%7.2f\n",_betamax,BETAMAX,cost5);
	printf("\t\t\t\t\t__________\n");
	printf("\t\t\tSUBTOTAL\t%7.2f\n", subTotal);
	printf("\t\t\tTAX\t\t%7.2f\n", tax1);
	printf("\t\t\tTotal\t\t%7.2f\n",total);

	return 0;

}
	
	
		



