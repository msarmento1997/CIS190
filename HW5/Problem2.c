/*Michael Sarmento
HW5 Problem2
11/27/19*/

//Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// function to sort the numbers at the given column
void columnNumbersSort(int col, float *jagged[5]);

// function to sort the numbers at all the columns
void sortColumns(float *jagged[5]);

// function to generate 30 random floats
void randomNumberGenerator(float num[]);

// function to allocate memory for a jagged array
void jaggedArrayCreation(float *jagged[5]);

// function to help the recursive quick sort
int partition(float array[], int low, int high);

// function to generate 30 random floats
void assignNumbersToArray(float *jagged[5],float num[30]);

// function to print the sorted jagged array row by row
void printJagged(float *jagged[5]);

// function to sort the array using the recursive quick sort
void recursiveQuickSort(float array[], int low, int high);




//main function
int main(){

  srand(time(0));

  //declaring arrays
  float *jagged[5];
  float num[30];

  //calling function to get 30 random float number and store it in num
  randomNumberGenerator(num);

  //this is called to create the jagged array
  jaggedArrayCreation(jagged);

  
  //print the initial jagged array to the user
  printf("Jagged array initially:\n\n");
  assignNumbersToArray(jagged, num);
  printJagged(jagged);

  //call this function to begin sorting the jagged array
  sortColumns(jagged);

  //print the sorted jagged array to the user
  printf("Jagged array sorted\n\n");
  printJagged(jagged);

  return 0;



}


// function to generate 30 random floats
void randomNumberGenerator(float num[])
{
  //declare varaibles
  int i;
  /*This for loop is used to generate 30 random numbers and store it in each
  index of the num array*/
  for (i = 0; i < 30; i++)
  {
    num[i] = ((float)rand() / (float)(RAND_MAX)) * 90 + 10;
  }

}


// function to allocate memory for a jagged array
void jaggedArrayCreation(float *jagged[5])
{
    /*allocating memory for the jagged array and giving the size of each row for this
    jagged array*/
    jagged[0] = malloc(sizeof(float) * 10);
    jagged[1] = malloc(sizeof(float) * 5);
    jagged[2] = malloc(sizeof(float) * 2);
    jagged[3] = malloc(sizeof(float) * 7);
    jagged[4] = malloc(sizeof(float) * 6);
}

// function to sort the numbers at the given column
void columnNumbersSort(int col, float *jagged[5])
{
    //declaring an array initialized with 0s and declaring other variables to be used
    float array[] = { 0, 0, 0, 0, 0 };
    int n = 0;
    int i=0,k;

  
    //loop to assign the values from each row of a specific column of the jagged array to a new array
    for(n=0;n<5;n++)
    {   
        /*these if statements are to make sure to garbage values are written into array
        it will write all the values of each column for each specific row into array if the jagged array
        contains a value in that specific position otherwise it will keep the default 0*/
        if(n==0 && col<10)
        {
          array[n]=jagged[n][col];
        }

        if(n==1 && col<5)
        {
          array[n]=jagged[n][col];
        }
        
        if(n==2 && col<2)
        {
          array[n]=jagged[n][col];
        }
        
        if(n==3 && col<7)
        {
          array[n]=jagged[n][col]; 
        }
        
        if(n==4 && col<6)
        {
          array[n]=jagged[n][col];
        }


    }

   
     //call the recursive quick sort
     recursiveQuickSort(array, 0, n - 1);
    
    


    /*this loop is used to reassign the sorted values that were stored into array back into the jagged array*/
    for(k=0;k<5;k++)
    {
        /*this if statements checks to make sure the values of array are being written into the specific row and column of the jagged array.
        The while loop checks to make sure the current value of array[i] is equal to 0, if it is then we will increment i until the value is no longer
        equal to 0, then we will store this value into the jagged array*/
        if(k==0 && col<10)
        {
          while(array[i]==0)
          {
            i++;
          }

          jagged[k][col]=array[i];
          i++;
          
        }
        
        if(k==1 && col<5)
        {
          while(array[i]==0)
          {
            i++;
          }
          jagged[k][col]=array[i];
          i++;
        }
        
        if(k==2 && col<2)
        {
          while(array[i]==0)
          {
            i++;
          }
          jagged[k][col]=array[i];
          i++;
        }
        
        if(k==3 && col<7)
        {
          while(array[i]==0)
          {
            i++;
          }
          jagged[k][col]=array[i];
          i++;
        }
        
        if(k==4 && col<6)
        {
          while(array[i]==0)
          {
            i++;
          }
          jagged[k][col]=array[i];
          i++;
        }
    }

   
}

// function to sort the numbers at all the columns
void sortColumns(float *jagged[5])
{
  /*for loop to go through each column and call columnNumberSort to sort numbers at each column*/
  for (int col = 0; col < 10; col++)
  {
    columnNumbersSort(col, jagged);
  }
}

// function to assign 30 random floats into the jagged array
void assignNumbersToArray(float *jagged[5],float num[30])
{
  //declared variables for loops
  int i = 0;
  int j;
  /*Eachloop is designed to assign the random generated numbers to the jagged array*/
  for (j = 0; j < 10; j++)
  {
      jagged[0][j] = num[i];
      i++;
  }

  for (j = 0; j < 5; j++)
  {
      jagged[1][j] = num[i];
      i++;
  }

  for (j = 0; j < 2; j++)
  {
    jagged[2][j] = num[i];
    i++;
  }
  for (j = 0; j < 7; j++)
  {
    jagged[3][j] = num[i];
    i++;
  }
  for (j = 0; j < 6; j++)
  {
    jagged[4][j] = num[i];
    i++;
  }
}

//partition and recursive quicksort from https://www.geeksforgeeks.org/quick-sort/
// function to help the recursive quick sort
int partition(float array[], int low, int high)
{
    //declared variables
    float pivot = array[low];
    int i = low;
    int j = high;
    //while loop for while i is less than j
    while (i < j)
    {
      //this loop increments i while it is less than or equal to pivot
      while (array[i] <= pivot)
      {
        i++;
      }
      //this loop decrements j while the array is greater than pivot
      while (array[j] > pivot)
      {
        j--;
      }
      
      //this if statement is used to swap the position of the values of array[i] and array[j]
      if (i < j)
      {
        float temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }

    array[low] = array[j];
    array[j] = pivot;
    //returns j
    return j;
}

// function to sort the array using the recursive quick sort
void recursiveQuickSort(float array[], int low, int high)
{
  /*This function uses the recursive quick sort that was given to us
  from the link*/
  if (low >= high)
  return;

  int s = partition(array, low, high);
  recursiveQuickSort(array, low, s - 1);
  recursiveQuickSort(array, s + 1, high);
}


// function to print the sorted jagged array row by row
void printJagged(float *jagged[5])
{
    //print first row
    for (int j = 0; j < 10; j++)
      printf("%0.2f ", jagged[0][j]);
      printf("\n");

    //print second row
    for (int j = 0; j < 5; j++)
      printf("%0.2f ", jagged[1][j]);
      printf("\n");

    //print third row
    for (int j = 0; j < 2; j++)
      printf("%0.2f ", jagged[2][j]);
      printf("\n");
    //print fourth row
    for (int j = 0; j < 7; j++)
      printf("%0.2f ", jagged[3][j]);
      printf("\n");
    //print fifth row
    for (int j = 0; j < 6; j++)
      printf("%0.2f ", jagged[4][j]);
      printf("\n\n");
}