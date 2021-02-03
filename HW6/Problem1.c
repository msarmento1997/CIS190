/*Michael Sarmento
CIS 190 HW6 part 1
12/6/19*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20

//typedef Structure;
typedef struct car
{
  char  name[SIZE];
  int   id;
  char color[SIZE];
  float price;
} CAR;

//functions
int partition(CAR *aptr, int low, int high);
void recursiveQuickSort(CAR *aptr, int low, int high);
void Print_Inventory(CAR *aptr, int low, int highest);
void swapChar(char *a, char *b);
void swapInt(int* a, int* b);
void swapFloat(float* a, float* b);
int userInput(CAR *aptr, int low, int high);
void userChoices();
int car_searched(CAR *aptr, int i);
int car_bought(CAR *aptr, int i);

int main()
{
  /* variables*/
  int i;
  int num;
  int low = 0, highest = -1;
  //for user input
  int input;
  int input_id, buyitem;


  //open file to read from
  FILE * readfile;
  readfile = fopen ("car.txt", "r");

  //check if there was an error reading file
  if (readfile == NULL)
  {
      fprintf(stderr, "Error opening file\n");
      
  }
  //scan the first num of the file to know the number of cars in stock
  fscanf(readfile, "%d",&num);
 
  //allocting memory using maaloc for CAR structure
  CAR *aptr = (CAR *) malloc (num * sizeof(CAR));

  //scans the name, id, color, and price of each vehicle
  for(i = 0; i < num; i++)
  {
      fscanf(readfile, "%s", aptr[i].name);
      fscanf(readfile, "%d", &aptr[i].id);
      fscanf(readfile, "%s", &aptr[i].color);
      fscanf(readfile, "%f", &aptr[i].price);
  }

  //this function is used for user input
  
  recursiveQuickSort(aptr, low, num-1);
  //Print_Inventory(aptr, low, num);
  userInput(aptr, low, num);

  return 0;
}

//Printing Inventory;
void Print_Inventory(CAR *aptr, int low, int highest)
{
  //variables
  int i,num;

  //this will print each cars information with proper formatting
  
  printf("\n|¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨|\n");
  printf("|CAR NAMES\t     ID\t     COLOR\t    PRICE|\n");
  for(i = low; i < highest; i++)
  {
    printf("|%9s\t", aptr[i].name);
    printf("%0.7d\t",aptr[i].id);
    printf(" %9s\t", aptr[i].color);
    printf(" %7.2f|\n",aptr[i].price);
  }
  printf("|________________________________________________|\n\n");
}



//https://www.geeksforgeeks.org/quick-sort/
int partition(CAR *aptr, int low, int high)
{
    //declared variables
    float pivot = aptr[high].price;    // pivot 
    int i = (low - 1);  // Index of smaller element 
    float temp;
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (aptr[j].price < pivot) 
        { 
            i++;    // increment index of smaller element 
           
            //swapping each piece of information in the proper location in memory
            swapChar(aptr[i].name, aptr[j].name);
            swapInt(&aptr[i].id, &aptr[j].id);
            swapChar(&aptr[i].color, &aptr[j].color);
            swapFloat(&aptr[i].price, &aptr[j].price);
            
        } 
    } 
    
    //swapping each piece of information in the proper location in memory
    swapChar(aptr[i+1].name, aptr[high].name);
    swapInt(&aptr[i+1].id, &aptr[high].id);
    swapChar(&aptr[i+1].color, &aptr[high].color);
    swapFloat(&aptr[i+1].price, &aptr[high].price);
            


    return (i + 1); 
}

//https://www.geeksforgeeks.org/quick-sort/
// function to sort the array using the recursive quick sort
void recursiveQuickSort(CAR *aptr, int low, int high)
{
  
   if (low < high) 
    { 
        
        int pi = partition(aptr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        recursiveQuickSort(aptr, low, pi - 1); 
        recursiveQuickSort(aptr, pi + 1, high); 
    } 
}


// swaps the strings (used for name and color)
void swapChar(char *a, char *b)
{
  int i;
  for(i = 0; i < SIZE; i++)
  {
    char t = *(a + i);
    *(a + i) = *(b + i);
    *(b + i) = t;
  }
}

//swaps two different intergers(used for id)
void swapInt(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//swaps to different floats(used for prices)
void swapFloat(float* a, float* b)
{
    float t = *a;
    *a = *b;
    *b = t;
}


//function that utilizes recursion to allow users to navigate and decide whether they want to view inventory, search for a vehicle or purchase one
int userInput(CAR *aptr, int low, int high)
{
    //variables
    int isValid=0;
    int valid=0;
    int valid2=0;
    int input;
    int id;
    int i;
    int number_cars;

    //display choices to user and receive their input
    userChoices();
    scanf("%d",&input);

    //check if the input is valid or not
    if(input!=1 && input!=2 && input !=3 && input !=4)
    {
      printf("\nInvalid Input! Please try again.\n");
      isValid=0;
    }
    else
    {
      isValid=1;
    }

    //if user input was invalid it will call upon the function again to ask the user for their input once more otherwise the program will continue on
    if(isValid!=1)
    {
      userInput(aptr, low, high);
    }
    else
    {
      //this will print the full inventory to the user on screen
      if(input==1)
      {
        Print_Inventory(aptr,low,high);
      }

      //this will display the vehicle the user searched for by id 
      if(input==2)
      {
        //loops to check if user input was valid
        while(valid == 0)
        {  
          //scans car id from user
          printf("\nPlease enter car ID: ");
          scanf("%d",&id);
          

          for(i=0;i<high;i++)
          {
            //if user id entered was valid then it will print the vehicle they searched for and exit the loop
            if(id == aptr[i].id)
            {
              valid=car_searched(aptr, i);
            } 
          }
          if(valid == 0)
          {
            printf("\nInvalid car ID entered!"); 
          }
        }
      }
      //if the user bought a vehicle displays the purchase order
      if(input==3)
      {
        //checks if user input was valid or not
        while(valid2 == 0)
        {  
          //asks user for valid id
          printf("\nPlease enter car ID you wish to purchase: ");
          scanf("%d",&id);
          
          //checks if id is valid and displays car the user bought with information
          for(i=0;i<high;i++)
          {
            if(id == aptr[i].id)
            {
              valid2=car_bought(aptr, i);
            } 
          }
          if(valid2 == 0)
          {
            printf("\nInvalid car ID entered!"); 
          }
        }
        //if the user bought a vehicle and the id was valid it will close the program
        return 0;

      }
      //exit the program
      if(input==4)
      {
        return 0;
      }

      //repeat the cycle again if the user didnt chose to buy a vehicle or close the program
      userInput(aptr, low, high);
    }


}

//displays user with vehicle information with proper formatting for id searched
int car_searched(CAR *aptr, int i)
{
  
  printf("\n|¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨|\n");
  printf("|CAR NAMES\t     ID\t     COLOR\t    PRICE|\n");
  printf("|%9s\t", aptr[i].name);
  printf("%0.7d\t",aptr[i].id);
  printf(" %9s\t", aptr[i].color);
  printf(" %7.2f|\n",aptr[i].price);
  printf("|________________________________________________|\n\n");
  return 1;
}

//displays user with purchase order for vehicle bought with proper formatting and information
int car_bought(CAR *aptr, int i)
{
  printf("\n|¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨|\n");
  printf("|\t\tPurchase Order\t\t\t |\n");
  printf("|CAR NAMES\t     ID\t     COLOR\t    PRICE|\n");
  printf("|%9s\t", aptr[i].name);
  printf("%0.7d\t",aptr[i].id);
  printf(" %9s\t", aptr[i].color);
  printf(" %7.2f|\n",aptr[i].price);
  printf("|________________________________________________|\n\n");
  return 1;
}


//displays user with prompt of choices
void userChoices()
{

  printf("\n1: For Full inventory\n");
  printf("2: To search by Car ID\n");
  printf("3: To buy a Car by ID\n");
  printf("4: To exit program\n");
  printf("Enter your choice: ");
}
