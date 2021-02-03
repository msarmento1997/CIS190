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


	FILE *input;
	
	input=fopen("input.txt", "r");
	
	/*print and scan users imputs for each item*/
	
	fscanf(input, "%d", &_jags);

	
	fscanf(input, "%d", &_cdi);
	
	
	fscanf(input, "%d", &_rem); 
	
	
	fscanf(input, "%d", &_3DO); 
	
	
	fscanf(input, "%d", &_betamax); 
	
	fclose(input);

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
	
	FILE *output;
	
	output = fopen("output.txt", "w");
	
	/*prints out a breakdown list of each cost to the user*/
	fprintf(input, "QTY\tDESCRIPTION\tUNIT PRICE\tTOTAL PRICE\n");
	fprintf(input, "___\t____________\t__________\t__________\n");
	fprintf(input, "%d\tJAGUAR\t\t%7.2f\t\t%7.2f\n",_jags,JAGUAR,cost1);
	fprintf(input, "%d\tCDI\t\t%7.2f\t\t%7.2f\n",_cdi,CDI,cost3);
	fprintf(input, "%d\tREMOTE CTRLR\t%7.2f\t\t%7.2f\n",_rem,REMOTE,cost2);
	fprintf(input, "%d\t3DO\t\t%7.2f\t\t%7.2f\n",_3DO,DO,cost4);
	fprintf(input, "%d\tBETAMAX\t\t%7.2f\t\t%7.2f\n",_betamax,BETAMAX,cost5);
	fprintf(input, "\t\t\t\t\t__________\n");
	fprintf(input, "\t\t\tSUBTOTAL\t%7.2f\n", subTotal);
	fprintf(input, "\t\t\tTAX\t\t%7.2f\n", tax1);
	fprintf(input, "\t\t\tTotal\t\t%7.2f\n",total);
	
	fclose(output);

	return 0;

}
