#include <stdio.h>
#include <malloc.h>
#include "My_lab.h"

void extr(int *mass, int size)
{
	int i = 0;
	if ((mass[i] < mass[i + 1]))
	{
		printf("lokal min %d \n", mass[i]);
	}
	else 
	{
		printf("lokal max %d \n", mass[i]);
	}
	while (i < size)
	{
		if (mass[i] < mass[i + 1])
		{
			while ((mass[i] < mass[i + 1]))
			{
				i++;
			}
			if (i >= size) break;
			printf("lokal max %d \n", mass[i]);
		}
		else
		{
			while ((mass[i] > mass[i + 1]))
			{
				i++;
			}
			if (i >= size) break;
			printf("lokal min %d \n", mass[i]);
		}
	}
}