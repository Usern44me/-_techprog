#include <stdio.h>
int 
main () 
{   
	int n, i, j, f;
	printf ("Prostiye chisla ot 2 do ");
	scanf ("%d", &n);
	if (n == 1)
	{
		printf ("1 ne prostoe chislo\n");
		return 0;
	}
	for (i=2; i<=n; i++)
    {
        f = 1;
        for (j=2; j<i; j++)
        {
            if (i % j == 0)
            {
                f = 0;
                break;
            }
        }
        if (f == 1)
            printf ("%d ", i);
    }
	return 0;
}
