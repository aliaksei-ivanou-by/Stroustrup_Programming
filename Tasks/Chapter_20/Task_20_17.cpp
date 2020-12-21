#ifndef TASK_20_17_STDAFX_H
#include "Task_20_17_stdafx.h"
#endif

int main()
try
{
	ownership_vector<int> myVector;
	myVector.push_back(new int(1));
	myVector.push_back(new int(2));
	int n = 2;
	myVector.push_back(n);
	++n;
	myVector.push_back(n);
	++n;
	myVector.push_back(n);
	for (auto i = 0; i < myVector.size(); ++i)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
	
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