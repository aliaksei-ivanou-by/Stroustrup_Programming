#ifndef TASK_19_02_STDAFX_H
#include "Task_19_02_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	std::vector<int> v1_int{ 1, 2, 3, 4, 5 };
	std::vector<int> v2_int{ 2, 3, 4, 5, 6 };
	std::vector<double> v3_double{ 1.1, 2.2, 3.1, 5.4, 8.3 };
	std::vector<double> v4_double{ 1.0, 2.3, 55.4, 3.2, 3.2 };

	std::cout << f<int>(v1_int, v2_int) << '\n';
	std::cout << f<double>(v1_int, v3_double) << '\n';
	std::cout << f<int>(v1_int, v4_double) << '\n';
	std::cout << f<double>(v1_int, v4_double) << '\n';
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