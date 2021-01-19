#ifndef TASK_26_12_STDAFX_H
#include "Task_26_12_stdafx.h"
#endif

int main()
try
{
	constexpr size_t size1 = 500'000;
	constexpr size_t size2 = 5'000'000;

	vector_generate_and_sort(size1);
	vector_generate_and_sort(size2);
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