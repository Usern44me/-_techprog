#ifndef _POINT_
#define _POINT_
#define _CRT_SECURE_NO_WARNINGS
class  bVect
{
private:
	int *str;
	int size;
public:
	bVect();
	void Otricanie();
	void Umnogit(const bVect &b);
	void Slogit(const bVect &b);
	void Sledovanie(const bVect &b);
	void Ravnoznach(const bVect &b);
	void Prisvo(const bVect &a);
	void Set(const int index, const int val);
	int Get(const int index);
	void Not_Slogit(const bVect &b);
	bVect(const bVect &a);
	void Display();
	~bVect();
};
#endif