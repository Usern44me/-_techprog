#include <stdio.h> 
#include <conio.h> 
#include<stdlib.h> 

//lib [i][j] == *(*(lib + i) + j) 

int 
check(char a) 
{ 
	return ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')); 
} 

int 
count_words(char *str) 
{ 
	int count = 0, in_word = 0, i; 
	
	for (i = 0; str[i] != '\0'; i++) 
	{ 
		if (check(str[i]) == 1) 
		in_word = 1; 
		else if (in_word == 1) 
		{ 
			in_word = 0; 
			count++; 
		} 
	} 
	return count; 
} 

void 
get_memory(char **lib, int num, int size_lib) 
{ 
	int i; 
	lib[size_lib] = (char *)malloc((num + 1) * sizeof(char)); 
	for (i = 0; i < (num + 1); i++) 
	{ 
		lib[size_lib][i] = 0; 
	} 
} 
//get_memory (str,num,size_lib); 

void 
get_in_lib(char **lib, int i, char *str, int num, int size_lib, int *result) 
{ 
	for (int j = 0; j < num; j++) 
	{ 
		if (check(str[i - num + j]) == 0) 
		{ 
			break; 
		} 
		*(*(lib + size_lib) + j) = str[i - num + j]; 
	} 
	*(*(lib + size_lib) + (num + 1)) = 0; 
	result[size_lib]++; 
} 

void 
arrprint(char **lib, int size_lib, int *result, int num) 
	{ 
	int j = 0; 
	for (int i = 0; i < size_lib; i++) 
	{ 
		if (result[i] == 0) 
		continue; 
		for (int j = 0; lib[i][j] != 0; j++) 
		{ 
			if (lib[i][j] != 0 && check(lib[i][j]) == 1) 
			{ 
				printf("%c", lib[i][j]); 
			} 
			else 
			break; 
		} 
		printf(" "); 
		printf("%d", result[i]); 
		printf("\n"); 
	} 
} 

int 
main() 
{ 
	char str[1000] = { 0 }; 
	int result[1000] = { 0 }; 
	int size_s = 0, size_w = 0, size_lib = 0; 
	int i, num = 0, count = 0, j, s, w, p, w_c = 0; 
	int var = 1; 
	printf("Input a line: "); 
	scanf("%c", &str[size_s++]); 
	while (str[size_s - 1] != '\n') 
	{ 
		scanf("%c", &str[size_s++]); 
	} 
	char **lib = (char**)malloc(count_words(str) * sizeof(char *)); 
	
	for (i = 0; i <= size_s; ++i) 
	{ 
		if (check(str[i]) == 1) 
		{ 
			num++; 
		} 
		else 
		{ 
			if (size_lib == 0) 
			{ 
				
				get_memory(lib, num, size_lib); 
				get_in_lib(lib, i, str, num, size_lib, result); 
				size_lib = 1; 
			} 
			else 
			{ 
				for (w = 0; w < size_lib; w++) 
				{ 
					int comp = num; 
					if (str[i - num] == lib[w][0]) 
					{ 
						for (j = 0; j <= num; j++) 
						{ 
							if (str[i - num + j] == lib[w][j]) 
							{ 
								comp--; 
							} 
						} 
					} 
					if (comp == 0) 
					{ 
						result[w]++; 
						var = 1; 
						break; 
					} 
					else var = 0; 
				
				} 
				if (var == 0) 
				{ 
					get_memory(lib, num, size_lib); 
					get_in_lib(lib, i, str, num, size_lib, result); 
					size_lib++; 
				} 
			} 
			num = 0; 
			if (check(str[i + 1]) == 0) 
			{ 
				i++; 
			} 
		} 
	} 
	arrprint(lib, size_lib, result, num); 
	
	for (int i = 0; i <= size_lib; i++) 
	{ 
		free(lib[i]); 
	} 
	free(lib); 
}
