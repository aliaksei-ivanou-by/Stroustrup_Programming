#ifndef TASK_19_01_STDAFX_H
#include "Task_19_01_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	std::vector<int> vInt1{ 1, 2, 3, 4 };
	std::vector<int> vInt2{ 5, 6, 7, 8 };
	f(vInt1, vInt2);
	std::cout << "vInt1: ";
	for (auto& i : vInt1)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	std::vector<std::string> vString1{ "a", "c", "e" };
	std::vector<std::string> vString2{ "b", "d", "f" };
	f(vString1, vString2);
	std::cout << "vString1: ";
	for (auto& i : vString1)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
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