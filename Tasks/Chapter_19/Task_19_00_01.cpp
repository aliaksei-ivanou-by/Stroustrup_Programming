#ifndef TASK_19_00_01_STDAFX_H
#include "Task_19_00_01_stdafx.h"
#endif

int main()
try
{
	vector v;

	v.resize(5);
	int i = 1;

	std::cout << "Step " << i++ << '\n';
	std::cout << "old capacity = \t" << v.capacity() << ", old size = \t" << v.size() << '\n';
	v.resize(20);
	std::cout << "new capacity = \t" << v.capacity() << ", new size = \t" << v.size() << '\n';

	std::cout << '\n';
	v.resize(10);

	std::cout << "Step " << i++ << '\n';
	std::cout << "old capacity = \t" << v.capacity() << ", old size = \t" << v.size() << '\n';
	v.resize(15); // 2
	std::cout << "new capacity = \t" << v.capacity() << ", new size = \t" << v.size() << '\n';

	std::cout << '\n';

	std::cout << "Step " << i++ << '\n';
	std::cout << "old capacity = \t" << v.capacity() << ", old size = \t" << v.size() << '\n';
	v.resize(15); // 3
	std::cout << "new capacity = \t" << v.capacity() << ", new size = \t" << v.size() << '\n';

	std::cout << '\n';

	std::cout << "Step " << i++ << '\n';
	std::cout << "old capacity = \t" << v.capacity() << ", old size = \t" << v.size() << '\n';
	v.resize(12); // 4
	std::cout << "new capacity = \t" << v.capacity() << ", new size = \t" << v.size() << '\n';

	std::cout << '\n';
	vector vv;
	vv.resize(10);

	std::cout << "old capacity = \t" << v.capacity() << ", old size = \t" << v.size() << '\n';
	v.resize(0);
	std::cout << "new capacity = \t" << v.capacity() << ", new size = \t" << v.size() << '\n';

	std::cout << '\n';

	std::cout << "old capacity = \t" << v.capacity() << ", old size = \t" << v.size() << '\n';
	v.resize(-77);
	std::cout << "new capacity = \t" << v.capacity() << ", new size = \t" << v.size() << '\n';
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