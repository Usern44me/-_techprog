#pragma
#include <set>

class MySet : public std::set<int>
{
public:
	MySet();
	~MySet();
	MySet combine(const MySet &s); //результатом является объединение множеств
	MySet intersect(const MySet &s); //результатом является пересечение множеств
	MySet minus(const MySet &s); //результатом является разность множеств
	
private:
	
};

MySet::MySet()
{
	
}

MySet::~MySet()
{
}

inline MySet MySet::combine(const MySet & s)
{
	MySet tmp;
	for (auto it = this->begin(); it != this->end() ; it++)
		tmp.insert(*it);
	for (auto it = s.begin(); it != s.end(); it++)
		tmp.insert(*it);
	return tmp;
}

inline MySet MySet::intersect(const MySet & s)
{
	MySet tmp;
	
	for (auto it = this->begin() ; it != this->end(); it++)
	{
		
		for(auto it2 = s.begin(); it2 != s.end(); it2++)
		{
			if (*it == *it2)
				tmp.insert(*it);
			if(*it2 == *it)
				tmp.insert(*it2);
		}
	}
	return tmp;
}

inline MySet MySet::minus(const MySet & s)
{
	MySet tmp;

	tmp = this->combine(s);
	MySet minus;
	minus = this->intersect(s);
	for (auto it = minus.begin(); it != minus.end(); it++)
	{
		tmp.erase(*it);
	}

	return tmp;
}

