#ifndef _CLASS_BASE_
#define _CLASS_BASE_
#include"Student.h"

class Class_base
{
private:
	student *students;
	int size_class;
public:
	Class_base();
	void add_student ();
	void ocenka_to_id(int n);
	void show();
	~Class_base();
};
#endif