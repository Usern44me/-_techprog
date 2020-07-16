#include <stdio.h>

int 
main ()
{
	char str[1000] = {0}, str2[1000] = {0}, word1[100] = {0}, word2[100] = {0};
	int size_s = 0, size_s2 = 0, size_w1 = 0, size_w2 = 0;
	int y = 1;
	printf ("Input a line:  ");
	scanf ("%c", &str[size_s ++]);
	while (str[size_s - 1] != '\n')
	{
		scanf ("%c", &str[size_s ++]);
	}
	
	printf ("Input a word:  ");
	scanf ("%c", &word1[size_w1 ++]);
	while (word1[size_w1 - 1] != '\n')
	{
		scanf ("%c", &word1[size_w1 ++]);
	}
	size_w1 --;

	printf ("Input a word:  ");
	scanf ("%c", &word2[size_w2 ++]);
	while (word2[size_w2 - 1] != '\n')
	{
		scanf ("%c", &word2[size_w2 ++]);
	}
	size_w2 --;
				
	for (int i = 0; i < size_w1; i ++)
	{
		if( !((word1[i] >= 'A' && word1[i] <= 'Z') || (word1[i] >= 'a' && word1[i] <= 'z')))
			{
				size_w1 = i;
				break;
			}
	}

	for (int i = 0; i < size_w2; i ++)
	{
		if ( !((word2[i] >= 'A' && word2[i] <= 'Z') || (word2[i] >= 'a' && word2[i] <= 'z')))
			{
				size_w2 = i;
				break;
			}
	}
	
	for ( int i = 0; i <= size_s; i ++)
	{
		if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			int comp = size_w1;
			if (str[i] == word1[0])
				{
					for (int j = 0; j < size_w1; j ++)
					{
						if (str[i + j] == word1[j])
						{	
							comp --;
						}
					}
				}
		
		if (comp == 0)
		{
			for (int j = 0; j < size_w2; j ++)
			{    
				str2[size_s2 ++] = word2[j];
			}
			printf("Proizvedina zamena na %d pozicii \n", i );
			
			i += size_w1;
			size_s = size_s - size_w1 + size_w2;
			str2[size_s2 ++] = str[i];
		}
		else
		{
			str2[size_s2 ++] = str[i];
		}
		}
		else 
		{    
			y++;
			str2[size_s2++] = str[i];
		}
		
		
		
	}
	printf ("Result: ");
	for (int i = 0; i <= size_s2 ; i ++)
	{
		printf ("%c", str2[i]);
	}
}


