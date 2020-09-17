#ifndef TASK_19_07_STDAFX_H
#include "Task_19_07_stdafx.h"
#endif

template<class C, class A, class B>
C f(std::vector<Number<A>>& vectorFirst, const std::vector<Number<B>>& vectorSecond)
{
	if (vectorFirst.size() != vectorSecond.size())
	{
		throw std::runtime_error("size of first vector != size of second vector");
	}
	C sum = 0;
	for (size_t i = 0; i < vectorFirst.size(); ++i)
	{
		sum = sum + vectorFirst[i] + vectorSecond[i];
	}
	return sum;
}

int main(int argc, char** argv)
try
{
	std::vector<Number<int>> v1_int{ 1, 2, 3, 4, 5 };
	std::vector<Number<int>> v2_int{ 2, 3, 4, 5, 6 };
	std::vector<Number<double>> v3_double{ 1.1, 2.2, 3.1, 5.4, 8.3 };
	std::vector<Number<double>> v4_double{ 1.0, 2.3, 55.4, 3.2, 3.2 };

	std::cout << f<Number<int>>(v1_int, v2_int) << '\n';
	std::cout << f<Number<double>>(v3_double, v4_double) << '\n';
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