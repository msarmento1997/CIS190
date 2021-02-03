#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int** array2d(int n)
{
	int** array = (int**)malloc(sizeof(int*)*n + sizeof(int)*n*n);
	array[0]= (int*)(array +n);//first dimenstion
	array[1] = (int*)(array[0] +n);

	for(int i=1;i<n;i++)
	{
		array[i]= (int*)(array[i-1]+n);
	}
}

int** array2d(int n)
{
	int** array = (int**)malloc(sizeof(int*)*n);

	int i;
	for (i=0;i<n; i++)
	{
		/* code */
		array[i] = (int*)malloc(sizeof(int*) *n);
	}
	return array;
}

int* range(int n)
{
	int* array =(int*)malloc(sizeof(int)*n);

	memcpy(array, array, sizeof(int)*n);
	memcpy(array, "default string", 15);

	memset(array, 0, sizeof(int)*n);


	array = (int*)realloc(array, sizeof(int) *(n+1));

	int i;
	for(i=0; i<n;i++)
	{
		array[i]=i;
	}

	return array;
}
int* range(int n)
{
	int* array =(int*)calloc(sizeof(int),n);

	int i;
	for(i=0; i<n;i++)
	{
		array[i]=i;
	}

	return array;
}

int main()
{
	int* array = range(n);

	free(array);

	int** array = array2d(9);
	//for 2d array
	int i;
	for(i=0;i<9;i++)
	{
		free(array[i]);
	}
	free(array);

}

//one call to malloc one call to free
//one call to calloc one call to free