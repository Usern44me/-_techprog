#include <stdio.h>
#include <malloc.h>
#include "My_lab.h"

int
main()
{
	int size;
	printf("Enter size \n");
	scanf_s("%d", &size);
	int *mass = new int(size + 1);
	printf("Enter mass \n");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &mass[i]);
	}
	
	extr(mass, size);
	delete [] &mass;
	return 0;
}