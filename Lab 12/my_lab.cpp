#include "bVect.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



bVect::bVect()
{
	this->size = 6;
	int tmp;
	int i;
	printf_s("Vvedite dvoichniy vector\n");
	this->str = new int[(this->size) + 1];
	for (i = 0; i < this->size; i++)
	{
		scanf_s("%d", &tmp);
		if ((tmp < 0) || (tmp > 1))
		{
			printf_s("(error) \n");
			i--;
		}
		else
		{
			str[i] = tmp;
		}
	}
}

int bVect::Get(const int index)
{
	if (index > this->size)
	{
		printf("Error index > size\n");
		return 0;
	}
	printf("%d",str[index]);
	_getch();
}

void bVect::Set(const int index, const int val)
{
	if (size <= index)
	{
		printf("Error, invalid index");
		_getch();

	}
	else
	{
		if (!((val < 0) || (val > 1)))
		{
			this->str[index] = val;
			this->Display();
		}
		else
		{
			printf("invalid value \n");
			_getch();
		}
	}
}

void bVect::Prisvo(const bVect &a)
{
	int i = 0;
	this->size = a.size;
	delete[] this->str;
	this->str = new int[a.size];
	for (i; i < a.size; i++)
	{
		this->str[i] = a.str[i];
	}
	printf("Success");
	_getch();
}

bVect::bVect(const bVect &a)
{
	int i = 0;
	this->size = a.size;
	this->str = new int[a.size + 1];
	for (i; i < a.size; i++)
	{
		this->str[i] = a.str[i];
	}
}

bVect::~bVect()
{
	delete[] str;
}

void bVect::Slogit(const bVect &b)
{
	int i;
	printf_s("Result: \n");
	for (i = 0; i < b.size; i++)
	{
		if ((this->str[i] == 1) || (b.str[i] == 1))
		{
			printf_s("1");
		}
		else
		{
			printf_s("0");
		}
	}
	printf_s("\n");
	_getch();
}

void bVect::Not_Slogit(const bVect &b)
{
	int i;
	printf_s("Result: \n");
	for (i = 0; i < b.size; i++)
	{
		if ((this->str[i] == 1) && (b.str[i] == 1))
		{
			printf_s("0");
			i++;
		}
		if ((this->str[i] == 1) || (b.str[i] == 1))
		{
			printf_s("1");
		}
		else
		{
			printf_s("0");
		}
	}
	printf_s("\n");
	_getch();
}
void bVect::Umnogit(const bVect &a)
{
	int i ;
	printf_s("Result: \n");
	for (i=0; i < a.size; i++)
	{
		if ((this->str[i] == 1) && (a.str[i] == 1))
		{
			printf_s("1");
		}
		else
		{
			printf_s("0");
		}
	}
	printf_s("\n");
	_getch();
}

void bVect::Otricanie()
{
	int i = 0;
	printf_s("Result: \n");
	for (i; i < this->size; i++)
	{
		if (this->str[i] == 1)
		{
			printf_s("0");
		}
		if (this->str[i] == 0)
		{
			printf_s("1");
		}
	}
	printf_s("\n");
	_getch();
}



void bVect::Sledovanie(const bVect &a)
{
	int i = 0;
	printf_s("Result: \n");
	for (i; i < a.size; i++)
	{
		if ((this->str[i] == 0) && (a.str[i] == 0))
		{
			printf_s("1");
		}
		if (a.str[i] == 1)
		{
			printf_s("1");
		}
		else
		{
			printf_s("0");
		}
	}
	printf_s("\n");
	_getch();
}


void bVect::Ravnoznach(const bVect &a)
{
	int i = 0;
	printf_s("Result: \n");
	for (i; i < a.size; i++)
	{
		if ((this->str[i] == 0) && (a.str[i] == 0))
		{
			printf_s("1");
		}
		if ((this->str[i] == 1) && (a.str[i] == 1))
		{
			printf_s("1");
		}
		else printf_s("0");
	}
	printf_s("\n");
	_getch();
}

void bVect::Display()
{
	for (int i = 0; i < this->size; i++)
	{
		printf("%d", this->str[i]);
	}
	printf("\n");
	_getch();
}