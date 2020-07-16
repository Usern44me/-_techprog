#define  _CRT_SECURE_NO_WARNINGS
#include "Data.h"
int 
main()
{
	Data a;
	a.Zapolnit();
	int count;
	a.Print();
	printf("Enter move \n");
	printf("1) = \n");
	printf("2) +=\n");
	printf("3) +\n");
	printf("4) ==\n");
	printf("5) >=\n");
	printf("6) <=\n");
	printf("7) != \n");
	printf("8) <\n");
	printf("9) >\n");
	printf("+) ++\n");
	printf("-) --\n");
	scanf("%d", &count);
	for ( int i= 0 ; i < 15; i ++)
	{
	switch (count)
	{
	case '1':
	{
		Data b;
		b.Zapolnit();
		a = b;
		printf("result: \n");
		a.Print();
		break;
	}
	case '2':
	{
		int var;
		printf(" a.day +=  \n");
		printf("enter number of days ");
		scanf("%d", &var);
		a += var;
		printf("result: \n");
		a.Print();
		break;
	}
	case '3':
	{
		int var;
		Data *c;
		printf(" c = a + ");
		printf("enter number of days ");
		scanf("%d", &var);
		c = (a+var);
		printf("result: \n");
		c->Print();
		break;
	}
	case '4':
	{
		Data b;
		b.Zapolnit();
		if (a == b)
		{
			printf("True\n");
			break;
		}
		else
		{
			printf("False\n");
			break;
		}
	}
	case '5':
	{
		Data b;
		b.Zapolnit();
		if (a >= b)
		{
			printf("True\n");
			break;
		}
		else
		{
			printf("False\n");
			break;
		}
	}
	case '6':
	{
		Data b;
		b.Zapolnit();
		if (a <= b)
		{
			printf("True\n");
			break;
		}
		else
		{
			printf("False\n");
			break;
		}
	}
	case '7':
	{
		Data b;
		b.Zapolnit();
		if (a != b)
		{
			printf("True\n");
			getchar();
			break;
		}
		else
		{
			printf("False\n");
			getchar();
			break;
		}
	}
	case '8':
	{
		Data b;
		b.Zapolnit();
		if (a < b)
		{
			printf("True\n");
			break;
		}
		else
		{
			printf("False\n");
			break;
		}
	}
	case '9':
	{
		Data b;
		b.Zapolnit();
		if (a > b)
		{
			printf("True\n");
			break;
		}
		else
		{
			printf("False\n");
			break;
		}
	}
	case '+':
	{
		a.operator++();
		printf("result: \n");
		a.Print();
		break;
	}
	case '-':
	{
		a.operator--();
		printf("result: \n");
		a.Print();
		break;
	}
	}
	count = getchar();
}
		return 0;
}