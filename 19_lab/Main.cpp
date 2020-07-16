#include <iostream>
#include <string>

void permutations(int *mass, int size, int pos = 0)
{
	if (pos >= size)
	{

		for (int i = 0; i < size; i++)
			std::cout << mass[i];


		std::cout << "\n"; 
		return;
	}
	else
	{
		for (int i = pos; i < size; ++i)
		{
			std::swap(mass[i], mass[pos]);
			permutations(mass, size, pos + 1);
			std::swap(mass[i], mass[pos]);
		}
		
	}
}


int 
main()
{
	int n;
	std::cout << "Enter n: ";
	std::cin >> n;
	
	int *mass = new int[n];

	for (int i = 0; i < n; i++)
	{
		std::cout << i + 1 << ") "; std::cin >>mass[i];
	}

	permutations(mass,n);

	system("pause");
	return 0;
}
