/*Michael Sarmento
Lab2
9/11/19*/
#include <stdio.h>
int main(){
	
	/*local varaible of int type*/
	int num;
	
	/*gets a random integer between 25 and 50*/
	srand(time(NULL));
	num = rand()%25+25;
	/*prints out random number*/
	printf("%d\n",num);
	
	return 0;

}
