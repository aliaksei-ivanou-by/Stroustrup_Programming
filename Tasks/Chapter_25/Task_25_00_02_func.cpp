#ifndef TASK_25__00_02_STDAFX
#include "Task_25_00_02_stdafx.h"
#include "Task_25_00_02_func.h"
#endif

void poor(Graph_lib::Shape* p, int sz)
{
	for (int i = 0; i < sz; ++i)
	{
		p[i].draw();
	}
}

void f(Graph_lib::Shape* q, std::vector<Graph_lib::Circle>& s0)
{
	Graph_lib::Polygon s1[10]; // OK
	//Graph_lib::Shape s2[10]; // Error - no default constructor
	Graph_lib::Shape* p1 = new Graph_lib::Rectangle{ Point{ 0, 0 }, Point{ 10, 20 } }; // OK 
	// poor(&s0[0], s0.size()); // Error
	// poor(s1, 10); // Error
	// poor(s2, 20); // Error - no default constructor
	poor(p1, 1); // OK
	delete p1; // OK
	p1 = 0; // OK
	// poor(p1, 1); // Error
	// poor(q, max); // Error - no 'max'
}