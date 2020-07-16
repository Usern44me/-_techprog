#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include "11lab.h"
using namespace std;


int 
main(int argc, char* argv[])
{
	if (!(argc > 3))
	{
		printf( "Not arguments");
		getchar();
		return 0;
	}
	char *str = (char*)calloc(100, sizeof(char));
	int mas_size = 0;
	std::ifstream fp;
	for (int i = 3; i < argc ; i += 2)
	{
			fp.open(argv[i], ios::in);
			if (!fp)
			{
				fprintf(stderr, "\nERROR! File %s dont exsist\n", argv[i]);
				exit(1);
			}
			char* mas = (char*)calloc(50, sizeof(char));
			for (int i = 0; !fp.eof(); i++)
			{
				fp >> mas[i];
			}
			mas_size += i;
			strcat(str, mas);
			fp.close();
			delete[]mas;
		
	}
	write_to_file(str, argv);
	return 0;
}

