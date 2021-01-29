#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

std::vector<double> func(const std::list<int>& myList)
{
	std::vector<double> myVector(myList.size());
	std::copy(myList.begin(), myList.end(), myVector.begin());
	if (myList.size() != myVector.size())
	{
		throw std::runtime_error("myList size != myVector size");
	}
	return myVector;
}

int main()
try
{
	std::list<int> myList{ 9, 8, 7, 6, 5, 4, 3, 2, 10};
	std::vector<double> myVector = func(myList);
	std::sort(myVector.begin(), myVector.end());
	for (const auto& i : myVector)
	{
		std::cout << i << ' ';
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