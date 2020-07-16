#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

void makeBMP(FILE* in, FILE* out)
{
	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER bih;
	RGBTRIPLE rgb;
	fread(&bfh, sizeof(bfh), 1, in);
	fwrite(&bfh, sizeof(bfh), 1, out);
	fread(&bih, sizeof(bih), 1, in);
	if (bih.biBitCount != 24)
	{
		fprintf(stdout, "\nERROR! this format of BMP is not supported.\n");
		exit(1);
	}
	fwrite(&bih, sizeof(bih), 1, out);
	int add = 0;
	if ((bih.biWidth * 3) % 4)
		add = 4 - (bih.biWidth * 3) % 4;
	int pos = 0;
	for (int i = bih.biHeight; i >= 0; i--)
	{
		for (int j = bih.biWidth / 2; j >= 0; j --)
		{
			fread(&rgb, sizeof(rgb), 1, in);
			fwrite(&rgb, sizeof(rgb), 1, out);
		}
		pos = ftell(in);
		for (int j = bih.biWidth / 2; j >= 0 ; j--)
		{
			fseek(in, pos - j - 1, SEEK_SET);
			fread(&rgb, sizeof(rgb), 1, in);
			fwrite(&rgb, sizeof(rgb), 1, out);
		}
			fread(&rgb, add, 1, in);
			fwrite(&rgb, add, 1, out);
	}
	fclose(in);
	fclose(out);
	//system("pause");
}
	
//≈сли все же хочешь через жопу, то pos = ftell(in) в конце строки, потом for (i = 0; i < width; i++) { fseek(in, pos - i - 1, SEEK_SET); fread(...); fwrite(...) } но это пиздец как медленно и костыльно.

//long now = ftell(in);
//fseek(in, 0, SEEK_END);
//long size = ftell(in);
//fseek(in, (size - now - bih.biWidth / 2), SEEK_END);
//fread(&rgb, sizeof(rgb), 1, in);
//fwrite(&rgb, sizeof(rgb), 1, out);
//fseek(in, (size - now - bih.biWidth / 2), SEEK_END);