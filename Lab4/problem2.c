/*MIchael Sarmento
Lab4
9/25/19*/

#include<stdio.h>

//to print the pattern
void pattern(int numberArray[],int size){
   int i, j, k;

   FILE *output;
   output = fopen("output.txt", "w");


   // for loop for printing
   // upper half
   for (i = 0; i < size; i++) {
       // printing i spaces at
       // the beginning of each row
       for (k = 0; k < i; k++)
           fprintf(output," ");
       // printing i to rows value
       // at the end of each row
       for (j = i; j < size; j++)
           fprintf(output,"%d ",numberArray[j]);

       fprintf(output,"\n");
   }

   // for loop for printing lower half
   for (i = size - 1; i >= 0; i--) {

       // printing i spaces at the
       // beginning of each row
       for (k = 0; k < i; k++)
           fprintf(output," ");


       // printing i to rows value
       // at the end of each row
       for (j = i; j < size; j++)
           fprintf(output,"%d ",numberArray[j]);

       fprintf(output,"\n");
   }
   fclose(output);
}

int main(){
  //to store the number
  int number;

  //get the number from the user
  printf("Enter n digit number: ");
  scanf("%d",&number);

  //make sure user input is valid
  while(1)
  {
    if(number<0||number>32767)
    {
      printf("\nWrong user input. Please try again.: ");
      scanf("%d",&number);
    }else
    {
      break;
    }

  }

  //first count the number of digits in the user input
  int count = 0;
  int n = number;

  while (n != 0){
  n /= 10;
  count++;
  }

  //store the number of digits in the size
  int size = count;

  //now store the number of digits in the array
  count--;
  if(count!=0){
  int numberArray[count];
  n = number;

  while (n != 0)
  {
    numberArray[count] = n % 10;
    n /= 10;
    count--;
  }

    //once the array is read call the pattern method to print the pattern
    pattern(numberArray,size);
  }
  return 0;

}
