#include <iostream>
#include <vector>

template<typename Iterator, typename T>
unsigned int myCount(Iterator first, Iterator last, const T& value)
{
	unsigned int counter = 0;
	while (first != last)
	{
		if (*first++ == value)
		{
			++counter;
		}
	}
	return counter;
}

template<typename Iterator, typename Predicate>
unsigned int myCountIf(Iterator first, Iterator last, Predicate predicate)
{
	unsigned int counter = 0;
	while (first != last)
	{
		if (predicate(*first++))
		{
			++counter;
		}
	}
	return counter;
}

int main()
try
{
	{
		std::vector<int> myVector = { 1, 2, 3, 4, 5, 6, 77, 54, 34, 2, 34, 4, 2, 23 };
		std::cout << "Number 2 in myVector (counts) : " <<
			myCount(myVector.begin(), myVector.end(), 2);
	}
	std::cout << '\n';
	{	
		std::vector<int> myVector = { 1, 2, 3, 4, 5, 6, 77, 54, 34, 2, 34, 4, 2, 23 };
		std::cout << "The number of even numbers in myVector: " <<
		myCountIf(myVector.begin(), myVector.end(),
			[](int v) { return v % 2 == 0; });
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