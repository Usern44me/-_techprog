#include<stdio.h>
#include"Student.h"
#include"Class.h"


student::student()
{
	this->id ;
	this->ocenki = new int [10];
	this->size_ocenki = 0;
}

void student::add_ocenka( int arr)
{
	if (size_ocenki == 9)
	{
		printf("------------------------------- \n");
		printf("ERROR! Not more space! \n");
		printf("------------------------------- \n");
	}
	else
	{
		ocenki[size_ocenki] = arr;
		size_ocenki++;
	}
}


student::~student()
{
	delete[] ocenki;
}