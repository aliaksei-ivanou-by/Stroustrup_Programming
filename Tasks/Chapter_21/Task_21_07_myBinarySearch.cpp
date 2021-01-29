#include <iostream>
#include <vector>
#include <list>
#include <string>

template<typename Iter, typename T>
bool myBinarySearch(Iter first, Iter last, const T& val)
{
	if (first == last)
	{
		return false;
	}
	if (*(--last) < val)
	{
		return false;
	}
	Iter low = first;
	Iter high = last;
	while (true)
	{
		if (low == high)
		{
			return false;
		}
		int distance = 0;
		Iter f = low;
		while (f != high)
		{
			++f;
			++distance;
		}
		Iter lowTemp = low;
		std::advance(lowTemp, distance / 2);
		Iter mid = lowTemp;
		T guess = *mid;
		if (guess == val)
		{
			return true;
		}
		if (guess > val)
		{
			--mid;
			high = mid;
		}
		else
		{
			++mid;
			low = mid;
		}
	}
	return false;
}

int main()
try
{
	std::vector<int> vec;
	constexpr size_t vecSize = 10;
	for (size_t i = 0; i < vecSize; ++i)
	{
		vec.push_back(i * 5);
	}
	std::cout << "Vector is :\n";
	for (const auto& i : vec)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	int vecNumber = vec[rand() % vecSize];
	std::cout << "Number for find is " << vecNumber << '\n';

	if (myBinarySearch(vec.begin(), vec.end(), vecNumber))
	{
		std::cout << "Binary Search for number " << vecNumber << " : number is found!\n";
	}
	else
	{
		std::cout << "Binary Search for number " << vecNumber << " : number isn't found!\n";
	}
	
	std::list<std::string> li;
	constexpr size_t liSize = 10;
	for (size_t i = 0; i < liSize; ++i)
	{
		li.push_back(std::string(1, 65 + i));
	}
	std::cout << '\n';
	
	std::cout << "List is :\n";
	for (const auto& i : li)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	std::string liLetter = "B";
	std::cout << "Letter for find is " << liLetter << '\n';

	if (myBinarySearch(li.begin(), li.end(), liLetter))
	{
		std::cout << "Binary Search for letter " << liLetter << " : letter is found!\n";
	}
	else
	{
		std::cout << "Binary Search for letter " << liLetter << " : letter isn't found!\n";
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