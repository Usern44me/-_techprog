#include "bVect.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

int 
main()
{
	int count;
	bVect a;
	printf_s("select an action : \n");
	printf_s("1) a A b\n");
	printf_s("2) a V b\n");
	printf_s("3) !a\n");
	printf_s("4) log consecution a from b\n");
	printf_s("5) log equivalence a from b\n");
	printf_s("6) set to index \n");
	printf_s("7) get to index\n");
	printf_s("8) display vector\n");
	printf_s("9) a !V b\n");
	scanf_s("%d\n", &count);
	switch (count)
	{
		case 1:
		{
			bVect b;
			a.Umnogit(b);
			a.Display();
			break;
		}
		case 2:
		{
			bVect b;
			a.Slogit(b);
			a.Display();
			break;
		}
		case 3:
		{
			a.Otricanie();
			a.Display();
			break;
		}
		case 4:
		{
			bVect b;
			a.Sledovanie(b);
			a.Display();
			break;
		}
		case 5:
		{
			bVect b;
			a.Ravnoznach(b);
			a.Display();
			break;
		}
		case 6:
		{
			int index;
			int val;
			printf("Enter value \n");
			getchar();
			scanf("%d", &val);
			
			printf("Enter index \n");
			getchar();
			scanf("%d", &index);
			a.Set(index, val);
			break;
		}
		case 7:
		{
			printf("Enter index \n");
			int index;
			scanf_s("%d", &index);
			getchar();
			a.Get(index);
			break;
		}
		case 8:
		{
			a.Display();
			break;
		}
		case 9:
		{
			bVect b;
			a.Not_Slogit(b);
			break;
		}
		default:
			printf_s("Nepravilni vvod \n");
			getchar();
	}
	return 0;
	
}

