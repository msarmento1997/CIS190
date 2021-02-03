/*Michael Sarmento
Problem1 part 1
11/13/19*/
#include <stdio.h>

#define SUBJECTS 2
#define STUDENTS 3
#define EXAMS 4

//functions
int average_of_all_grades(int grades,int count, int sum);
void average_grade_per_student_and_subject(int arr[][EXAMS], int k);
int average_grade_per_student_both_subjects(int arr2[], int sum, int i, int count);

int main()
{
	//local variables
	int i,j,k;
	int count=1;
	int sum;

	//array which contains the grades for each student per subject
	int array[SUBJECTS][STUDENTS][EXAMS]=
	{
		//plane 0(subject1)
		{{68,82,90,75},//row 0(student0)
		{65,89,71,57},//row 1(student1)
		{92,87,63,83}},//row 2(student2)
		
		//plane 1(subject2)
		{{70,59,67,88},//row 0(student0)
		{40,60,79,71},//row 1(student 1)
		{81,73,79,94}},//row 2(student2)
	};

	//printf("%d\n",***array);
	//average_of_all_grades(array);
	
	//printf("Whats up %d\n",**array[2]);
	
	//printf("%d\n",*array[0][2]);

	//passing a plane to the function
	for(i=0,k=0;i<SUBJECTS;i++,k++)
	{
		average_grade_per_student_and_subject(array[i],k);

	}

	//average_of_all_grades(array);

	//passing element by element to the function
	for(i=0;i<SUBJECTS;i++)
	{
		for(j=0;j<STUDENTS;j++)
		{
			for(k=0;k<EXAMS;k++)
			{
				//sum is used to hold the total sum of the grades and count is the terminating variables once it reaches 24
				sum=average_of_all_grades(array[i][j][k], count, sum);
				count++;
			}
		}
	}

	
	//passing a row of a specific plane at a time to the function
	//sum is used to return the previous sum from the first subject in order to calculate the sum of both subjects and the average
	for(i=0;i<STUDENTS;i++)
	{
		//count is used as a terminating case
		count=0;
		sum=0;
		for(j=0;j<SUBJECTS;j++)
		{	//subjects increase quicker then students that way we can get the grades of both subjects for each student
			sum=average_grade_per_student_both_subjects(array[j][i], sum, i, count);
			count++;
		}
	}

}




//calculate the average grades per student and subject
void average_grade_per_student_and_subject(int arr[][EXAMS],int k)
{
	//variables
	int i;
	int j;
	int sum;
	double average;


	for(i=0;i<STUDENTS;i++)
	{	
		//reinitialize sum and average to 0
		sum=0;
		average=0;
		for(j=0;j<EXAMS;j++)
		{
			//printf("%d\n",arr[i][j]);

			//add grade to sum
			sum+=arr[i][j];
			if(j == EXAMS -1)
			{	//calculating the average grade per student and subject and print to user
				average = ((double)sum/(double)EXAMS);
				printf("Student %d Subject %d Average: %.2lf\n",i,k,average);
			}
		}

	}
}

//calculate the average of all the grades
int average_of_all_grades(int grade,int count,int sum)
{	
	double average;
	//if the count equals 24 then the average will be computed
	if(count==24)
	{	//add the final grade to sum
		sum+=grade;
		//calculate average of all th egrades and print it to the user
		average = ((double)sum/(double)count);
		printf("Average of all the grades: %.2lf\n",average);
	}else
	{
		//calculate sum and return sum
		sum+=grade;
		return sum;
	}
}

//calculate average grades per student for both their subjects
int average_grade_per_student_both_subjects(int arr2[], int sum, int i, int count)
{
	//variables
	int k;
	double average;

	for(k=0;k<EXAMS;k++)
	{	//add grades to sum for both subjects while containing the first grades of the previous subject
		sum+=arr2[k];
		//printf("%d %d\n",k,arr2[k]);
	}

	//terminating case
	if(count==1)
	{
		//printf("Sum: %d\n",sum);
		//calculates the average of both subjects per student and prints it to the user
		average=((double)sum/(double)(SUBJECTS*EXAMS));
		printf("Student %d Average grades for both subjects: %.2lf\n",i,average);

	}
	return sum;
}