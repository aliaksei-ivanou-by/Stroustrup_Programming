#ifndef TASK_21_00_06_STDAFX_H
#include "Task_21_00_06_stdafx.h"
#endif

int main()
try
{
	std::string from = "Task_21_00_06.txt";
	std::string to = "Task_21_00_06_out.txt";

	std::ifstream is(from.c_str());
	if (!is)
	{
		throw std::runtime_error("Can't open the file");
	}
	std::ofstream os(to.c_str());

	std::istream_iterator<std::string> ii(is);
	std::istream_iterator<std::string> eos;
	std::ostream_iterator<std::string> oo(os, "\n");

	std::vector<std::string> b(ii, eos);
	std::sort(b.begin(), b.end());
	copy(b.begin(), b.end(), oo);
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