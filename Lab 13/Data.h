#ifndef _POINT_
#define _POINT_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class Data
{
private:
	 int day;
	 int month;
public:
	Data();
	void Zapolnit();
	void Print();
	Data* operator+(int a) const;
	Data*  operator+=(int a);
	Data operator=(const Data &a);
	int operator==(const  Data &a);
	int operator!=(const Data &a);
	int operator<=(const Data &a);
	int operator>=(const Data &a);
	int operator<(const Data &a);
	int operator>(const Data &a);
	void operator++();
	void operator--();
	~Data();

};

#endif