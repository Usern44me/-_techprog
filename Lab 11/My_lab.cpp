#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include "11lab.h"

using namespace std;

void write_to_file(char *mas, char **argv)
{
	ofstream fp;
	fp.open(argv[1], ios::trunc | ios::out);

	fp << mas;
	fp.close();
}
