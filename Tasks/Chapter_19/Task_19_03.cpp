#ifndef TASK_19_03_STDAFX_H
#include "Task_19_03_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	std::vector<Pair<std::string, double>> table;
	table.push_back({ "pi", 3.141592653589 });
	table.push_back({ "e", 2.718281828459 });
	std::cout << "Constants Table :\n";
	for (size_t i = 0; i < table.size(); ++i)
	{
		std::cout << table[i] << '\n';
	}
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