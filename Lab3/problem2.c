/*Michael Sarmento
9/18/19
Lab3*/

#include <stdio.h>


int main(void){

  /*local variables*/
  double dnum;
  int inum;
  int num1;
  int count=0;
  //int power=1;
  int i;
  //dnum=12345678.99;

  /*Reading from input file to get a double value */
  FILE *input;
  input = fopen("input.txt", "r");
  fscanf(input, "%lf",&dnum);
  fclose(input);

  /*initialize inum by casting a dnum into an int*/
  inum=(int)dnum;


  /*Find the total digit count*/
  while(inum !=0)
  {
    inum/=10;
    ++count;
  }

  /*create an arr called s with enough space to fit the digits of inum in */
  int s[count];
  inum=(int)dnum;
  //prints digit count
  printf("\nDigit Count:%d\n", count);

  /*for loop to store each digit into the array in reverse order*/
  for(i=0;i<count;i++)
  {
    num1=inum%10;
    inum/=10;
    s[i]=num1;
  //  printf("%d",s[i]);
  }

  //Write to a file output
  FILE *output;
  output = fopen("output2.txt", "w");

  //this loop will print out the odd digits in order
  fprintf(output,"Odd Digits: ");
  for(i=count-1;i>=0;i=i-2)
  {
    fprintf(output,"%d ",s[i]);
  }

  //this loop will print out the even digits in order
  fprintf(output, "\n\nEven Digits: ");
  for(i=count-2;i>=0;i=i-2)
  {

    fprintf(output,"%d ",s[i]);
  }
  //close output file
  fclose(output);

  return 0;

}
