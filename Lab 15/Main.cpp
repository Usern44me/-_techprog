#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include "lab15.h"

int main(int argc, char const *argv[])
{
	if (argc > 3)
	{
		fprintf(stderr, "\nERROR! Too many input files.\n\nCorrect format: lab15.exe /* path to the input file or file name */ /* path to the outpit file or file name */\n");
		return 1;
	}
	if (argc < 3)
	{
		fprintf(stderr, "\nERROR! Too few input files.\n\nCorrect format: lab10.exe /* path to the file or file name */ /* path to the output file or file name */\n");
		return 1;
	}
	FILE* input = fopen(argv[argc - 2], "rb");
	if (input == NULL)
	{
		fprintf(stderr, "\nERROR! Can not open input file.\n");
		return 1;
	}
	FILE* output = fopen(argv[argc - 1], "wb");
	if (output == NULL)
	{
		fprintf(stderr, "\nERROR! Can not open output file.\n");
		return 1;
	}
	makeBMP(input, output);
	fprintf(stdout, "\nNew BMP-file is created succesfully!\n");
	return 0;
}