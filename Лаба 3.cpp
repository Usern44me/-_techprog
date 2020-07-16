#include<stdio.h>
int
power (int x, int n)
{
	int a = 1;
	while ( n != 0 )
	{
		if ( n != 0 )
		{
			a = a * x;
			n --;
		}
		else
		{
			return 1;
		}
	}
	return a;

}

int
main ()
{
	int x, n;
	printf ("wwedite 2 argumenta \n");
	scanf ("%d", &x);
	scanf ("%d", &n);
	if (power (x, n) != -1)
	{
		printf ("%d", power(x, n));
	}
	else 
	{
		printf ("Znachenie 2 argumenta ne mozhet bit' otricatelnim \n");
	}

}
