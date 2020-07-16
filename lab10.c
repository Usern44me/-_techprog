#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lab10.h"

void file_to_mas ()
{
	FILE *fp = fopen ("f1.c", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "\nERROR! Can not open c-file\n");
		exit (1);
	}
	fseek (fp, 0, SEEK_END);
	int mas_size = ftell (fp);
	fseek (fp, 0, SEEK_SET);
	char* mas = (char*) malloc ((mas_size + 1) * sizeof (char));
	*(mas + mas_size) = 0;
	for (int i = 0; !feof (fp); i++) {
	*(mas + i) = getc (fp); 
		if(*(mas + i) == '{')
		{
			*(mas + i + 1) = '\t';
			i++;
		}
		if (*(mas + i) == '}')
		{
			*(mas + i + 1) = '\b';
			i++;
		}
		}
	fclose (fp);
	write_in_file( mas, mas_size);
}



void write_in_file(char* mas,int mas_size )
{
	FILE *fp = fopen (".c", "w");
	fwrite( mas, sizeof(char), mas_size, fp );
	fclose (fp);
}
