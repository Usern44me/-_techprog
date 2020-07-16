#ifndef _POLYNOM_
#define _POLYNOM_

class Polynom
{
private:
	int* koef;
	int degree;
public:
	Polynom(int a);
	~Polynom();
	Polynom (const Polynom& pol);
	void operator *= (Polynom& t);
	void Zapolnit(int num);
	void Print();
};
#endif
