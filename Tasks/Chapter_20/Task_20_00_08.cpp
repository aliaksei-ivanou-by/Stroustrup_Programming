#include <iostream>
#include <vector>
#include <list>

void funInt(const int myInt[], const int size)
{
	std::cout << "funInt\n";
	std::cout << size << " is myInt size\n";
}

void funVector(const std::vector<int>& myVector)
{
	std::cout << "funVector\n";
	std::cout << myVector.size() << " is myVector size\n";
}

void funcList(const std::list<int>& myList)
{
	std::cout << "funcList\n";
	std::cout << myList.size() << " is myList size\n";
}

int main()
try
{
	int myInt[] = { 1, 2, 3, 4, 5 };
	funInt(myInt, sizeof(myInt) / sizeof(myInt[0]));
	std::cout << '\n';

	std::vector<int> myVector = { 1, 2, 3, 4, 5 };
	funVector(myVector);
	std::cout << '\n';

	std::list<int> myList = { 1, 2, 3, 4, 5 };
	funcList(myList);
	std::cout << '\n';
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