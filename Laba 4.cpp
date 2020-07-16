#include <stdio.h> 

int func1(char *str, int size_w)
{
	int i, num = 0, count = 0, k;
	for (i = 0; *(str + i - 1) != 0 || i == 0; i++)
	{
		if ((*(str + i) >= 'a' && *(str + i) <= 'z') || (*(str + i) >= 'A' && *(str + i) <= 'Z'))
		{
			num++;
		}
		else
		{
			if (num == size_w)
			{
				for (k = 0; k < size_w; k++)
				{
					printf("%c", *(str + i - size_w + k));
				}
				printf("\n");
				count++;
			}
			num = 0;
		}
	}
	printf("%d\n", count);
}

int
main()
{	
	char str[1000] = { 0 }, word[100] = { 0 };
	int size_s = 0, size_w = 0;

	printf("Input a line: ");
	scanf("%c", &*(str + size_s++));
	while (*(str + size_s - 1) != '\n')
	{
		scanf("%c", &*(str + size_s++));
	}

	printf("Input a word: ");
	scanf("%c", &*(word + size_w++));
	while (*(word + size_w - 1) != '\n')
	{
		scanf("%c", &*(word + size_w++));
	}
	size_w--;
	
	func1 (str, size_w);
	return 0;
}
