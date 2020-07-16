#include<iostream>
#include<stdio.h>
#include"Polynom.h"


int 
main(){
	setlocale(LC_ALL, "Russian");
	int n;
	std::cout << "¬ведите n\n";
	std::cin >> n;
	int *a = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		std::cout << "¬ведите a" << i + 1 << "\n";
		std::cin >> a[i];
	}
	
	Polynom p(1);
	p.Zapolnit(a[0]);
	Polynom b(1);
	int sum = (a[0] * a[1]);
	b.Zapolnit(sum);
	for (int i = 2; i <= n; i++)
	{
		p *= b;
		sum *= a[i];
		b.Zapolnit(sum);
	}
	p.Print();
	system("pause");
	return 0;
}