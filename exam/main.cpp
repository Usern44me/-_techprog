#include<stdio.h>
#include"Student.h"
#include"Class.h"


int 
main()
{
	Class_base a;
	int count = -1;
	while(count != 0)
	{
		printf("Enter action: \n");
		printf("1)Add student \n");
		printf("2)Add ocenka to id \n");
		printf("3)Show class base\n");
		printf ("0)Exit\n");
		scanf("%d", &count);
		switch (count)
		{
			case 1 :
			{
				a.add_student();
				break;
			}
			case 2:
			{
				int arr;
				printf("Enter id \n");
				scanf_s("%d",&arr);
				a.ocenka_to_id(arr);
				break;
			}
			case 3:
			{
				a.show();
				break;
			}
			case 0:
				{
					return 0;
				}
		}
	}
}