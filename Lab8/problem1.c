#include <stdio.h>


#define STUDENTS 3
#define SUBJECT 2
#define TESTS 4

void func_average(int array[STUDENTS][SUBJECT][TESTS]);
void func_subject_average(int array[STUDENTS][SUBJECT][TESTS]);
void func_average_grade_per_student(int array[STUDENTS][SUBJECT][TESTS]);


int main()
{
	int array[STUDENTS][SUBJECT][TESTS]=
	{
		{{97, 86, 95, 89}, {34, 54, 21, 10}},
		{{97, 86, 95, 89}, {34, 54, 21, 10}},
		{{97, 86, 95, 89}, {34, 54, 21, 10}},
	};

	func_average(array);
	func_subject_average(array);
	func_average_grade_per_student(array);

	

}

void func_average(int array[STUDENTS][SUBJECT][TESTS])
{
	int i, j, k;
	int sum=0;
	int average;

	for(i=0;i<STUDENTS;i++)
	{
		for(j=0;j<SUBJECT;j++)
		{
			for(k=0;k<TESTS;k++)
			{
				sum += array[i][j][k];
			}
		}
	}

	average = sum/(STUDENTS * SUBJECT * TESTS);

	printf("Test average: %d\n", average);
}

void func_subject_average(int array[STUDENTS][SUBJECT][TESTS])
{
	int i, j, k;

	int sum_subject1=0;
	int sum_subject2=0;
	int average_subject1;
	int average_subject2;

	for(i=0;i<STUDENTS;i++)
	{
		for(j=0;j<SUBJECT;j++)
		{
			for(k=0;k<TESTS;k++)
			{
				if(j==0)
					sum_subject1 += array[i][j][k];
				if(j==1)
					sum_subject2 += array[i][j][k];
			}
		}
	}
	average_subject1 = sum_subject1/ (STUDENTS * TESTS);
	average_subject2 = sum_subject2/ (STUDENTS * TESTS);

	printf("Average for Subject 1: %d\n", average_subject1);
	printf("Average for Subject 2: %d\n", average_subject2);
}

void func_average_grade_per_student(int array[STUDENTS][SUBJECT][TESTS])
{
	int i, j, k;

	int sum_subject1_student=0;
	int sum_subject2_student=0;
	int average_subject1_student;
	int average_subject2_student;
	int total_sum_student;
	int total_average_student;


	for(i=0;i<STUDENTS;i++)
	{
		sum_subject1_student =0;
		sum_subject2_student =0;
		average_subject1_student =0;
		average_subject2_student =0;
		total_sum_student =0;
		total_average_student = 0;

		for(j=0;j<SUBJECT;j++)
		{
			for(k=0;k<TESTS;k++)
			{
				if(i==0)
				{
					if(j==0)
					{
						sum_subject1_student +=array[i][j][k];


					}

					if(j==1)
					{
						sum_subject2_student +=array[i][j][k];

					}

					if(k== TESTS-1 && j==1)
					{
						average_subject1_student = sum_subject1_student/(TESTS);
						average_subject2_student = sum_subject2_student/(TESTS);

						total_sum_student = sum_subject1_student + sum_subject2_student;
						total_average_student = total_sum_student/(SUBJECT * TESTS);

						printf("\n\n***Student1 Averages***\n");
						printf("Student1 Subject 1 Average: %d\n",average_subject1_student);
						printf("Student1 Subject 2 Average: %d\n",average_subject2_student);
						printf("Student1 Total Average for both subjects: %d\n", total_average_student);

					}

				}
				if(i==1)
				{
					if(j==0)
					{
						sum_subject1_student +=array[i][j][k];


					}

					if(j==1)
					{
						sum_subject2_student +=array[i][j][k];

					}

					if(k== TESTS-1 && j ==1)
					{
						average_subject1_student = sum_subject1_student/(TESTS);
						average_subject2_student = sum_subject2_student/(TESTS);

						total_sum_student = sum_subject1_student + sum_subject2_student;
						total_average_student = total_sum_student/(SUBJECT * TESTS);

						printf("***Student2 Averages***\n");
						printf("Student2 Subject 1 Average: %d\n",average_subject1_student);
						printf("Student2 Subject 2 Average: %d\n",average_subject2_student);
						printf("Student2 Total Average for both subjects: %d\n", total_average_student);

					}

				}
				if(i==2)
				{
					if(j==0)
					{
						sum_subject1_student +=array[i][j][k];


					}

					if(j==1)
					{
						sum_subject2_student +=array[i][j][k];

					}

					if(k== TESTS-1 && j ==1)
					{
						average_subject1_student = sum_subject1_student/(TESTS);
						average_subject2_student = sum_subject2_student/(TESTS);

						total_sum_student = sum_subject1_student + sum_subject2_student;
						total_average_student = total_sum_student/(SUBJECT * TESTS);

						printf("***Student3 Averages***\n");
						printf("Student3 Subject 1 Average: %d\n",average_subject1_student);
						printf("Student3 Subject 2 Average: %d\n",average_subject2_student);
						printf("Student3 Total Average for both subjects: %d\n", total_average_student);

					}

				}

			}
		}
	}

}
