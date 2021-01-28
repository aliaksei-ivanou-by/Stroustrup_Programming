#ifndef TASK_19_11_STDAFX_H
#include "Task_19_11_stdafx.h"
#endif

counted_ptr<int> getInt(int number)
{
	counted_ptr<int> pointer{ number };
	return pointer;
}

int main(int argc, char** argv)
try
{
	counted_ptr<int> pointer1{ 200 };
	std::cout << "pointer1 : " << *pointer1 << '\n';

	counted_ptr<int> pointer2 = pointer1;
	std::cout << "pointer2 : " << *pointer2 << '\n';

	counted_ptr<int> pointer3 = getInt(250);
	std::cout << "pointer3 : " << *pointer3 << '\n';

	counted_ptr<int> pointer4 = pointer3;
	std::cout << "pointer4 : " << *pointer4 << '\n';

	std::vector<counted_ptr<int>> vector;
	vector.push_back(pointer1);
	vector.push_back(pointer2);
	vector.push_back(pointer3);
	vector.push_back(pointer4);
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