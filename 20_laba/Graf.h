#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <vector>
#include <list>


class graf
{
public:
	graf(std::string &str);
	void from_file(std::string &str);
	void connectivity_components();
	friend std::ostream& operator<< (std::ostream& os, const graf &a)
	{

		for (unsigned int i = 0; i < a.matrix.size(); ++i)
		{
			for (unsigned int j = 0; j < a.matrix[i].size(); ++j)
			{
				os << a.matrix[i][j] << ' ';
			}

			os << "\n";
		}
		return os;
	}
private:
	std::vector<std::vector<int>> matrix;
	int start = 0;
	void dfs(int v, std::vector<bool>  &visited, std::vector<int> &a);
};

graf::graf(std::string &str)
{
	this->from_file(str);
}




void graf::from_file(std::string &str)
{

	unsigned  int i = 0, k = 0;
	std::vector<char> v;
	if (FILE *fp = fopen(str.c_str(), "r"))
	{
		char buf[1024];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			v.insert(v.end(), buf, buf + len);

		fclose(fp);
	}

	i = 0;
	while (v[i] != '\n')
	{
		i++;
	}
	matrix.resize(v[i - 1] - '0' + 1);

	while (v[i] != '\0')
	{
		i++;
		for (k = 0; v[i + k] != '\n' && i + k < v.size() - 1; k++)
		{
			if (v[i + k] == '0' && k != 0)
			{
				matrix[v[i] - '0'].push_back(0);
			}
			if (v[i + k] == '1' && k != 0)
			{
				matrix[v[i] - '0'].push_back(1);
			}
			if (v[i + k] == '-' && k != 0)
			{
				matrix[v[i] - '0'].push_back(-1);
				k++;
			}
		}
		if (i + k == v.size() - 1 )break;
		i += k;
	}
	if (v[i + k - 1] - '0' > matrix[1].size())
		i++;
	start = v[i + k - 1] - '0';
	std::cout <<"Start:" << start << std::endl;
}


void graf::dfs(int v, std::vector<bool>  &visited, std::vector<int> &a)
{
	int j;
	a.push_back(v);
	visited[v] = true;
	for (j = 0; j < matrix[1].size(); ++j)
	{
		if (matrix[v][j] == -1)
		{
			if (visited[j] == false)
			{
				dfs(j, visited, a);
			}
		}
	}
	if (j == matrix[1].size())
	{
		int i;
		for (i = 0; i < a.size() -1; i++)
		{
			std::cout << a[i] << "--";
		}
		std::cout << a[i]  <<std::endl;
		if(a.size() != 1)
		a.pop_back();
	}
	return;
}

void graf::connectivity_components()
{
	std::vector<int> a;
	std::vector<bool>  visited;
	for (int i = 0; i < matrix.size(); ++i)
	{
		visited.push_back(false);
	}
	dfs(start, visited,a);
}