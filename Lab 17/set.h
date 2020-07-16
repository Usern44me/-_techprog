#pragma once
#include <iostream>
#include "Point.h"
#include "exception.h"

template <class T>
class set
{
public:
	set();
	~set();
	bool find(const T &value);
	int BinSearch(const T &k);
	void insert(const T &value);
	set<T> uniîn(const set<T> &s) const;
	friend std::ostream& operator<< (std::ostream& os, const set<T> a) 
	{
		os << "{ ";
		for (int n = 0; n < a.size(); n++)
		{
			os << a.massiv[n] << ", ";
		}
		os << " }";
		return os;
	/*	os << a.massiv[0] << std::endl;
		os << a.massiv[a.size() - 1] << std::endl;
		return os;*/
	}
	int size() const;
	T *massiv;
protected:
	/*void bubble_sort(T array[], int size);*/
	
	int mass_size;
	
};

template <typename T>
set<T> set<T>::uniîn(const set<T> &s) const
{
	set<T> res;

	try
	{
		if ((s.mass_size == 0) || (this->mass_size == 0))
		{
			throw("Massiv is empty");
		}
	}
	catch (const exception& e)
	{
		e.what();
	}
		

	for (int i = 0; i < s.mass_size; i++)
	{
		res.insert(s.massiv[i]);
	}

	for (int i = 0; i < this->mass_size; i++)
	{
		res.insert(this->massiv[i]);
	}

	return res;
	
}


template <typename T>
set<T>::set()
{
	this->mass_size = 0;
}

template <typename T>
set<T>::~set()
{
	delete[]massiv;
}

template <typename T>
int set<T>::size() const
{
	return this->mass_size;
}



template <typename T>
void set<T>::insert(const T &value)
{
	if (mass_size == 0)
	{
		this->mass_size++;
		massiv = new T[size()];
		massiv[0] = value;
	}
	if (find(value) == false)
	{
		T *tmp;
		tmp = new T[size()];
		for (int i = 0; i < this->size() ; i++)
		{
			tmp[i] = this->massiv[i];
		}

		/*delete[]massiv;*/


		if (BinSearch(value) == this->size())
		{
			
			for (int i = 0; i < this->size(); i++)
			{
				this->massiv[i] = tmp[i];
			}
			this->mass_size++;
			this->massiv[size() - 1] = value;
		}
		else
		{
			this->mass_size++;
			int n;
			for (int i = 0, n = 0; i < size(); i++)
			{
				
				if (n == BinSearch(value))
				{
					this->massiv[n] = value;
					n++;
				}
				this->massiv[n] = tmp[i];
				n++;
			}
		}
		delete[]tmp;
	}
}

template <typename T>
int set<T>::BinSearch(const T &key)
{

	if (mass_size == 1)
	{
		int a;
		if (key > massiv[0])
		{
			a = 1;
		}
		else
		{
			a = 0;
		}
		return a;
	}
	int left = 0; 
	int right = this->size();
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2; 
		if (key == this->massiv[mid]) {  
			return mid;  
		}
		if (key < this->massiv[mid])     
			right = mid - 1;  
		else                 
			left = mid + 1; 
	}
	if (mid == this->size())
		return (this->size());
	if (left >= right)  
		return left;
}



template <typename T>
bool set<T>::find(const T &key)
{
	
	if (key == massiv[BinSearch(key)])
	{
		return true;
	}
	else return false;
}


//template<typename T>
//void set<T>::bubble_sort(T array[], int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		for (int j = 0; j < size - i - 1;j++)
//		{
//			if (array[j + 1] < array[j])
//			{
//				std::swap(array[j], array[j + 1]);
//			}
//		}
//	}
//}











