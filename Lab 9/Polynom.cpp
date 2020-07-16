#include<iostream>
#include<stdio.h>
#include"Polynom.h"


Polynom::Polynom(int a)
{
	this->degree = a;
	this->koef = (int*)calloc(degree + 1, sizeof(int));
}
Polynom::~Polynom()
{
	delete[] koef;
}

Polynom::Polynom(const Polynom& pol)
{
	degree = pol.degree;
	koef = new int[degree + 1];
	for (int i = degree; i >= 0; i--)
		koef[i] = pol.koef[i];
}

void Polynom::Print()
{
	for (int i = degree; i > 0 ; i--)
	{
		if (i != 1)
		{
			std::cout << koef[i] << "x^" << i << " + ";
		}
		else
		{
			std::cout << koef[i] << "x" << " + ";
		}
	}
	std::cout << koef[0] ;
	std::cout <<"\n";
}

void Polynom::Zapolnit(int num)
{
		koef[1] = 1;
		koef[0] = num;
}

void Polynom::operator *= (Polynom& pol)
{
	Polynom tmp(this->degree);
	tmp = *this;
	this->degree = pol.degree + tmp.degree;
	this->koef = (int*)calloc(this->degree + 1,sizeof(int));
	for (int i = 0; i < this->degree; i++)
	{
		for (int k = 0; k <= pol.degree; k++)
		{
			this->koef[i + k] += tmp.koef[i] * pol.koef[k];
		}
	}
}

