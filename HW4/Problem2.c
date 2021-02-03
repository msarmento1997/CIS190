/*Michael Sarmento
Problem2
11/13/19*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 256

//functions
int isCity(char *string, char cities[][14]);
void getCity(int *string, char cities[][14]);
void calculatePaths(int map[10][10], int destCity, int visitedCitiesList[10], int curCity, int *totalPaths, int paths[10][10], int visitedCount, int curPath[10], int onlyShortest, int curSum, int *shortestPath);
void printPaths(int map[10][10], int paths[10][10], char cities[][14], int totalPaths);
int getYesNo(void);

int main()
{
	//I used the array from France, Spain and Portugal on the map given to create my own map
	//array map of cities
	int map[10][10]={
		{0,140,80,110,0,0,0,125,100,0},//Paris
		{140,0,0,70,120,0,0,130,0,130},//Barcelona
		{80,0,0,100,0,0,0,0,0,0},//Nantes
		{110,70,100,0,75,55,75,0,0,0},//San Sebastian
		{0,120,0,75,0,55,65,0,0,75},//Madrid
		{0,0,0,55,55,0,60,0,0,0},//Santiago
		{0,0,0,75,65,60,0,0,0,0},//Lisbon
		{125,130,0,0,0,0,0,0,0,0},//Nice
		{100,0,0,0,0,0,0,0,0,0},//Brest
		{0,130,0,0,75,0,0,0,0,0}};//Grenada

	//Cities indexed by map correlation
	char cities[][14]=
	{
		"Paris",
		"Barcelona",
		"Nantes",
		"San Sebastian",
		"Madrid",
		"Santiago",
		"Lisbon",
		"Nice",
		"Brest",
		"Grenada"
	};

	int srcCity;
	int destCity;
	int i;

	//print all the city options
	printf("City Options:\n");
	for(i=0;i<10;i++)
		printf("%s\n",cities[i]);

	//ask user for starting city
	printf("\nEnter starting city: ");
	getCity(&srcCity,cities);

	//ask user for city destination 
	printf("\nEnter destination city: ");
	getCity(&destCity, cities);

	//ask user if they want the shortest path only or all the paths
	printf("Do you only want the shortest path? (Press Y) Do you want all paths? (Press N)");
	int shortestOnly = getYesNo();

	printf("\n");


	if(srcCity != destCity)
	{
		//variables required to calculate all paths
		int visitedCitiesList[10]={0};
		int paths[100][10]={0};
		int curPath[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
		int totalPaths = 0;
		int shortest = 99999;

		//Recursively calculate the valid paths to array PATHS
		calculatePaths(map,destCity, visitedCitiesList, srcCity, &totalPaths, paths, 0, curPath, shortestOnly,0,&shortest);
		
		if(shortestOnly == 1)//If only one path, the shortest, is being printed:
			printf("Shortest path from %s to %s is %d miles:\n\n",cities[srcCity],cities[destCity],shortest);
		else//If it's more than one path:
			printf("Calculated a total of %d paths from %s to %s:\n\n",totalPaths,cities[srcCity],cities[destCity]);

		//Print the paths that were calculated above:
		printPaths(map,paths,cities,totalPaths);

	}else
	{
		printf("You don't have to travel anywhere, you are already at your destination.\n");
	}

	printf("\n");
	return 0;
}

//Gets 1 (yes) or 0 (no) for the shortest path only.
int getYesNo(void)
{
	char response[BUFFER] = {'0'}; //declare string buffer for city name to be returned
	do{
		fgets(response,BUFFER,stdin);
		if(response[0] != 'Y' && response[0] != 'N')
			printf("Invalid input!\nEnter Y (yes) or N (no): ");
	}while(response[0] != 'Y' && response[0] != 'N');
	
	if(response[0] == 'Y')
		return 1;
	else //Default to no if char somehow is not N:
		return 0;
}


//Prints the paths based on if you want the smallest or all:
void printPaths(int map[10][10], int paths[10][10], char cities[][14], int totalPaths)
{
	int i, j,sum,lowest,shortindex;
	//For each path that was determined:
	for(i = 0; i < totalPaths; i++)
	{	
		
		for(j = 0; j < 10; j++)
		{
			printf("%s", cities[paths[i][j]]);	//Print the path
			if(paths[i][j+1] == -1) //If the next value is -1 (unused) the break.
				break;
			sum+=map[paths[i][j]][paths[i][j+1]]; //Add the corresponding miles from the map to the running sum

			printf(" to ");
		}
		
		if(sum < lowest) //swap them if the sum is a smaller path:
		{
			lowest = sum;
			shortindex = i;
		}
		printf(" (%d mi)\n",sum); //print the miles of the trip and a new line.
		sum = 0; //Reset the sum for the next path
	}
}

//Calculate all possible paths from one city to another. Sets each path to a new row of Paths recursively.
void calculatePaths(int map[10][10], int destCity, int visitedCitiesList[10], int curCity, int *totalPaths, int paths[10][10], int visitedCount, int curPath[10], int onlyShortest, int curSum, int *shortestPath)
{	
	int i; //loop variable
	visitedCitiesList[curCity] = 1;	//Set the current city to already visited so we never go back twice.
	curPath[visitedCount] = curCity; //Set the current path's index to the current city integer.
	visitedCount++;	//Increment the visit count
	
	//Set the totalPaths index to 0 so it will copy to the correct path address.
	if(onlyShortest == 1)
		*totalPaths = 0;
	
	//If the current city is the destination city.
	if(curCity == destCity)
	{	
		if(onlyShortest == 1 && curSum > *shortestPath) //If only shortest path is required but the current path is longer than the last.
		{	
			goto after; //Don't copy the new path if it's longer.
		}

		*shortestPath = curSum; //Set the current sum to the shortest path and reset the cursum
		curSum = 0; //Reset the current sum since its a valid path.
		
		//We copy the current path to the next available path in the paths array:
		for(i = 0; i < 10; i++)
		{
			paths[*totalPaths][i] = curPath[i]; //Set the corresponding path in paths (with correct row) to the current Path's city
		} //Will copy to [0][i] if onlyShortest = 1
		
		//Increment our path count if we are not getting the shortest only.
		if(onlyShortest == 0)
			(*totalPaths)++;

	}else{	//If the current city is NOT the destination city:
		//Search each index for flyable cities:
		for(i = 0; i < 10; i++)
		{
			//If the city can be flown to and has not been visited:
			if(map[curCity][i] != 0 && visitedCitiesList[i] == 0)
			{
				//If we can fly there, use the new city (i) for the curCity.
				calculatePaths(map,destCity,visitedCitiesList,i,totalPaths,paths,visitedCount,curPath,onlyShortest,curSum+map[curCity][i],shortestPath); //Call again to find the next step with the city at index i, adding the current miles to the city to curSum.
			}
		}	
	}
	after:
	
	for(i = visitedCount; i < 10; i++)
		curPath[i] = -1;	//Loop back all unused curPath to -1 so we dont mess up the next path.
	
	//Reset after the last iteration so the loop printing knows its only 1 path.
	if(onlyShortest == 1)
		*totalPaths = 1;
		
	visitedCount--;	//Decrease city count
	visitedCitiesList[curCity] = 0; //Set it to unvisited.
}

//Gets user input for the city name, and validates it to make sure its in our list of cities then returns it to the address of string.
void getCity(int *string, char cities[][14])
{
	char rCity[BUFFER] = {'0'}; //declare string buffer for city name to be returned
	do{
		fgets(rCity,BUFFER,stdin); //get user input from keyboard and return it to address of srcCity
		rCity[strlen(rCity) - 1] = 0; //Fixes array size for string.
	}while(isCity(rCity,cities) == -1); //While input is not a city on our list
	*string = isCity(rCity,cities); //Set the string pointer to the current city name
}

//Checks the given string to see if it's in our list of cities. Then returns 0 if it is, 1 if not.
int isCity(char *string, char cities[][14])
{
	int i; //loop variable
	for(i = 0; i < 10; i++)//for each city in our list
	{
		if(strcmp(string,cities[i]) == 0) //compare it to our input string
			return i; //If they are the same, return 0.
	}
	//If it's not equal to any city in our list, say invalid and return 1.
	printf("Invalid input!\nEnter the city again: ");
	return -1;
}