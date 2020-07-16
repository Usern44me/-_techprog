#include <stdio.h>
#include "my_lab.h"

float
fact ( float n )
{
	float a = 1;
	for( float i = 2 ; i <= n; ++i )
	{
		a *= i; 
	}
	return a;
}

float calculate ( float epsilon )
	{
		float t;
		float e = 0;
		for( float i = 0; i < 10 ; i++)
		{
			t = e;
			e = e + (1 / fact (i));
			if ((e - t) <= epsilon)
				{
				return t;
				}
		}
	}