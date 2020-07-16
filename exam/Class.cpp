#include<stdio.h>
#include<stdlib.h>
#include"Class.h"
#include"Student.h"



Class_base::Class_base()
{
	this->students = new student[100];
	this->size_class = 0;
}

void Class_base::add_student ()
{
	if (size_class == 99)
	{
		printf("------------------------------- \n");
		printf("ERROR! Not more space! \n");
		printf("------------------------------- \n");
	}
	else
	{
		printf("Enter id \n");
		int n;
		scanf_s ("%d",&students[size_class].id);
		size_class++;
	}
}

void Class_base::ocenka_to_id(int n)
{
	for(int i = 0; i < size_class; i ++)
	{
		if(students[i].id == n)
		{
			int arr;
			printf ("Enter ocenka \n");
			scanf_s ("%d", &arr);
			students[i].add_ocenka(arr);
			break;
		}
	}
}


void Class_base::show()
{
	for(int i = 0; i < size_class; i ++)
	{
		printf("%d: ",students[i].id);
		for(int j = 0; j < students[i].size_ocenki; j ++)
		{
			printf("%d ", students[i].ocenki[j]);
		}
		printf("\n");
	}
}

Class_base::~Class_base()
{
	delete[] students;
}
