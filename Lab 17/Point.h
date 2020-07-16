#pragma once

struct point
{
	int x;
	int y;
	int z;
	point(point const &b)
	{
		x = b.x;
		y = b.y;
		z = b.z;
		std::cout << "This copy constructor!" << std::endl;
	}
	point()
	{
		x = 0;
		y = 0;
		z = 0;
		std::cout << "This constructor!" << std::endl;
	}

	bool operator<(point const&a)
	{
		if ((x < a.x) && (y < a.y) && (z < a.z))
		{
			return 1;
		}
		else return 0;
	}
	bool operator==(point const&a)
	{
		if ((x == a.x) && (y == a.y) && (z == a.z))
		{
			return 1;
		}
		else return 0;
	}
	
	point& operator= (point const&a)
	{
		x = a.x;
		y = a.y;
		z = a.z;

		return *this;
	}
};

std::ostream& operator<< (std::ostream& os, point a)
{
	os << a.x << "\n";
	os << a.y << "\n";
	os << a.z << "\n";
	return os;
}



