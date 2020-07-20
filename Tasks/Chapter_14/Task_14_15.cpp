#ifndef TASK_14_15_STDAFX_H
#include "Task_14_15_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	std::cout << "Vector 1\n";
	std::vector<double> v1{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Vector_iterator v_it1(v1);
	print(v_it1);
	std::cout << "\nList 1\n";
	std::list<double> l1{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	List_iterator l_it1(l1);
	print(l_it1);
	std::cout << "\nVector 2\n";
	std::vector<double> v2;
	Vector_iterator v_it2(v2);
	print(v_it2);
	std::cout << "\nList 2\n";
	std::list<double> l2;
	List_iterator l_it2(l2);
	print(l_it2);
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