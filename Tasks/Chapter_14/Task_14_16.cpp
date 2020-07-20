#ifndef TASK_14_16_STDAFX_H
#include "Task_14_16_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	// 1
	Graph_lib::Controller_Show c1(0, 255);
	std::cout << "Controller c1\n";
	c1.show();
	// 2
	Graph_lib::Controller_Color c2(1, 60);
	std::cout << "Controller c2\n";
	c2.set_mycolor();
	std::cout << "Color is " << c2.color().as_int() << '\n';
	// 3
	Graph_lib::Controller_Color_Fill c3(1, 55);
	std::cout << "Controller c3\n";
	c3.set_myfill_color();
	std::cout << "Color is " << c3.fill_color().as_int() << '\n';
	return 0;
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}