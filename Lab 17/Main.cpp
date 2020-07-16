#include<iostream>

#include "Point.h"
#include"set.h"
#include <conio.h>



int
main()
{

	set<int> a;
	a.insert(5);
	a.insert(4);
	a.insert(4);
	a.insert(6);
	a.insert(7);
	a.insert(5);
	a.insert(1);

	//set<int> b;
	//b.insert(7);
	//b.insert(7);
	//b.insert(1);
	//b.insert(0);
	//b.insert(4);
	//b.insert(4); 

	std::cout << a <<std::endl;
	
	/*set<int> t;*/
	//a.uniîn(t);

	//set<double> d;
	//d.insert(6.262);
	//d.insert(2.1110);
	//d.insert(5.2235);

	//set<char> n;
	//n.insert("i");
	//n.insert("n");
	//n.insert("a");
	//n.insert("f");
	//n.insert("i");
	//n.insert("n");
	//set<char> m;
	//m.insert("b");
	//m.insert("n");
	//m.insert("k");
	//m.insert("l");
	//m.insert("c");
	//m.insert("e");
	//n.uniîn(m);


	/*point z;
	z.x = 1;
	z.y = 2;
	z.z = 3;
	point v;
	v.x = 10;
	v.y = 11;
	v.z = 23;
	set<point> p;
	p.insert(v);
	p.insert(z);*/
	////
	////set<point> p2;
	////point c;
	////c.x = 0;
	////c.y = 7;
	////c.y = 2;
	////p2.insert(c);
	////p.uniîn(p2);
	
	_getch();
	return 0;
}