/*Michael Sarmento
Problem1 Part 2
11/13/19*/
#include <stdio.h>

#define SUBJECTS 2
#define STUDENTS 3
#define EXAMS 4

//functions
int average_of_all_grades(int grade, int count, int sum);
int average_grade_per_student_both_subject(int arr[],int count,int i, int sum);
int average_grade_per_student_and_subjects(int arr[][SUBJECTS], int count,int k,int *sum1, int *sum2, int *sum3);


int main()
{	//variables 
	int i,j,k;
	int sum;
	int count=1;
	int sum1=0, sum2=0, sum3=0;

	//array which contains the grades per student and subject
	int array[EXAMS][STUDENTS][SUBJECTS]=
	{
		//Plane1(EXAM 0)
		{{68,70},//Student0(subject1 and 2)
		 {65,40},//student1(subject1 and 2)
		 {92,81}},//student2(subject1 and 2)
		
		 //Plane2(EXAM 1)
		{{82,59},//student0(subject1 and 2)
		 {89,60},//student1(subject1 and 2)
		 {87,73}},//student2(subject1 and 2)

		//Plane3(EXAM 2)
		{{90,67},//student0(subject1 and 2)
		 {71,79},//student1(subject1 and 2)
		 {63,79}},//student2(subject1 and 2)

		//Plane 4(EXAM 3)
		{{75,88},//student0(subject1 and 2)
		 {57,71},//student1(subject1 and 2)
		 {83,94}},//student2(subject1 and 2)

	};

	//passing element by element
	for(i=0;i<EXAMS;i++)
	{
		for(j=0;j<STUDENTS;j++)
		{
			for(k=0;k<SUBJECTS;k++)
			{	//sum is used to hold the total sum of the grades and count is the terminating variables once it reaches 24
				sum=average_of_all_grades(array[i][j][k], count,sum);
				count++;
			}
		}
	}

	//passing a specific row at a time, where the row increases faster than the column
	for(i=0;i<STUDENTS;i++)
	{	//reinitialize values
		sum=0;
		count =0;
		for(j=0;j<EXAMS;j++)
		{	//returns sum after each run
			sum = average_grade_per_student_both_subject(array[j][i], count,i, sum);
			count++;
		}
		
	}

	count=0;
	//passing a plane
	for(i=0;i<EXAMS;i++)
	{
		k=0;
		//this will calculate all the averages of the exams for the first subject per student
		average_grade_per_student_and_subjects(array[i],count,k,&sum1,&sum2,&sum3);
		count++;

	}

	//reinitialize values
	count=0;
	sum1=0;
	sum2=0;
	sum3=0;
	//passing a plane 
	for(i=0;i<EXAMS;i++)
	{	k=1;
		//this will calculate the average of all the exams for the second subject per student
		average_grade_per_student_and_subjects(array[i],count,k,&sum1,&sum2,&sum3);
		count++;
	}


}

//calculate the average of all the grades
int average_of_all_grades(int grade, int count, int sum)
{
	double average;

	//if the count equals 24 then the average will be computed
	if(count==24)
	{	//add the final grade to sum
		sum +=grade;
		//calculate average of all th egrades and print it to the user
		average = ((double)sum/(double)count);
		printf("Average of all the grades: %.2lf\n",average);
	}
	else
	{	//calculate sum 
		sum+=grade;
	}

	return sum;
}

//calculate average grade per student for both subjects
int average_grade_per_student_both_subject(int arr[], int count,int i, int sum)
{	
	//variables
	int k;
	double average;
	//loop to get each grade added to sum
	for(k=0;k<SUBJECTS;k++)
	{
		sum+=arr[k];
	}
	//terminating condition
	if(count==3)
	{	
		//prints the average grade per student for both subjects
		average=((double)sum/(double)(EXAMS*SUBJECTS));
		printf("Student %d Average grades for both subjects %.2lf\n",i, average);
	}
	return sum;
}

//function to calculate average grades per student and per subject
int average_grade_per_student_and_subjects(int arr2[][SUBJECTS], int count,int k,int *sum1, int *sum2, int *sum3)
{
	int i;

	double average1,average2,average3;
	for(i=0;i<STUDENTS;i++)
	{
			//check which student we are looking at and use a pointer to hold the cummaltive value of grades
			if(i==0)
				*sum1+=arr2[i][k];
			if(i==1)
				*sum2+=arr2[i][k];
			if(i==2)
				*sum3+=arr2[i][k];
		
	}

	//terminating case
	if(count ==3)
	{	//calcu;ate the average grade per subject for each student
		average1=((double)*sum1/(double)EXAMS);
		average2=((double)*sum2/(double)EXAMS);
		average3=((double)*sum3/(double)EXAMS);
		//print all the average grades per student and per subject
		printf("Student 0 Subject %d Average grade %.2lf\n",k,average1);
		printf("Student 1 Subject %d Average grade %.2lf\n",k,average2);
		printf("Student 2 Subject %d Average grade %.2lf\n",k,average3);

	}

}