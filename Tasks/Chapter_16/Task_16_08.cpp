#ifndef TASK_16_08_STDAFX_H
#include "Task_16_08_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Currency_converter win(Point(100, 100), 400, 200, "Currency Converter");
	return gui_main();
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