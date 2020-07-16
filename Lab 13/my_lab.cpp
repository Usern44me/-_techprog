#define  _CRT_SECURE_NO_WARNINGS
#include "Data.h"


Data::Data()
{
	this->day ;
	this->month ;
}
Data::~Data()
{

}

void Data::Zapolnit()
{
	int m, d;
	printf("Enter month \n");
	scanf("%d", &m);
	if (m > 12)
	{
		for (int i = 0; m > 12; i++)
		{
			printf("Error, in year only 12 months \n");
			scanf("%d", &m);
		}
	}
	this->month = m;
	printf("Enter day \n");
	scanf("%d", &d);
	if (d > 30)
	{
		for (int i = 0; d > 30; i++)
		{
			printf("Error, in month only 30 days ) \n");
			scanf("%d", &d);
		}
	}
	this->day = d;
	
}

void Data::Print()
{
	printf("%d.%d \n", this->day, this->month);
}


Data*  Data::operator+=(int a)
{

	if ((a + this->day) > 30)
	{
		this->month = this->month + 1;
		this->day = this->day + a - 30;
		if (this->month > 12)
		{
			this->month = 1;
		}
	}
	else
	{
		this->day = this->day + a;
	}
	return this;
}


Data* Data::operator+(int a) const
{
	Data* tmp = new Data();
	if ((a + this->day) > 30)
	{
		tmp->month = this->month + 1;
		tmp->day = this->day + a - 30;
		if (tmp->month > 12)
		{
			tmp->month = 1;
		}
	}
	else
	{
		tmp->day = this->day + a;
		tmp->month = this->month;
	}
	
	return tmp;
}



Data Data:: operator = (const Data &a)
{
	this->day = a.day;
	this->month = a.month;
	return  *this;
}


int Data::operator==(const  Data &a)
{

	if (!(this->day > a.day) && !(this->day < a.day))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int Data::operator!=(const Data &a)
{
	if ((this->day > a.day) && (this->day < a.day))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Data::operator<=(const Data &a)
{
	if ((this->month < a.month) || (this->month = a.month))
	{
		if ((this->day < a.day) || (this->day = a.day))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int Data::operator>=(const Data &a)
{
	if ((this->month > a.month) || (this->month = a.month))
	{
		if ((this->day > a.day) || (this->day = a.day))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}


int Data::operator<(const Data &a)
{

	if ((this->day < a.day) && (this->month < a.month))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Data::operator>(const Data &a)
{

	if ((this->day > a.day) && (this->month > a.month))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void Data::operator++()
{
	this->day+= 1;
	if (this->day > 30)
	{
		this->day = 1;
		this->month += 1;
	}
}

void Data::operator--()
{
	this->day -= 1;
}

