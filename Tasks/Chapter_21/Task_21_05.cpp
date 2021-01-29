#include <iostream>
#include <vector>

template<typename In, typename T>
bool myFind(In& first, In last, const T& val)
{
	while (first != last)
	{
		if (*first == val)
		{
			return true;
		}
		++first;
	}
	return false;
}

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

int main()
try
{
	srand(static_cast<unsigned int>(time(NULL)));
	std::vector<int> vec;
	constexpr size_t vecSize = 20;
	for (size_t i = 0; i < vecSize; ++i)
	{
		vec.push_back(static_cast<int>(rand() % 100));
	}
	std::cout << "Vector is :\n";
	for (const auto& i : vec)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
	int vecNumber1 = vec[rand() % vecSize];
	std::cout << "Number for find is " << vecNumber1 << '\n';
	
	auto vecIt = vec.begin();
	if (myFind(vecIt, vec.end(), vecNumber1))
	{
		std::cout << "Number is found : " << *vecIt << "\n\n";
	}
	else
	{
		std::cout << "Number isn't found\n\n";
	}

	int vecNumber2 = vec[rand() % vecSize];
	std::cout << "Number " << vecNumber2 << " counts : " << 
		myCount(vec.begin(), vec.end(), vecNumber2) << '\n';
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