#include "Graf.h"
#include <string>
#include <iostream>

int
main()
{
	std::cout << "Enter file name with graf" << std::endl;
	std::string str;
	getline(std::cin, str);
	graf g(str);
	std::cout << g << std::endl;
	g.connectivity_components();

	system("pause");
	return 0;
}