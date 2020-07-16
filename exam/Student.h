#ifndef _STUDENT_
#define _STUDENT_

class student
{
private:
public:
	int *ocenki;
	int size_ocenki;
	int id;
	student();
	student(int n);
	void add_ocenka(int arr);
	~student();
};
#endif