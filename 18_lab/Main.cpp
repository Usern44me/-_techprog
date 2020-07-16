#include <iostream>
#include <conio.h>
#include "MySet.h"

int main()
{
	MySet example;
	example.insert(1);
	example.insert(3);
	example.insert(3);
	example.insert(5);
	example.insert(9);
	MySet example1;
	example1.insert(1);
	example1.insert(5);
	example1.insert(8);
	example1.insert(7);
	example1.insert(12);
	example1.insert(0);
	
	//MySet a = example.combine( example1);
	MySet b = example.minus( example1);
	//MySet c = example.intersect( example1);
	
	for (auto it = b.begin(); it !=b.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	_getch();
	return 0;
}