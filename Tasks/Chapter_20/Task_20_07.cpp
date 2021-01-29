#include <iostream>
#include <vector>
#include <string>

template<typename Iterator1, typename Iterator2>
auto findLast(Iterator1 first, Iterator2 last)
{
	Iterator1 high = first;
	while (first != last)
	{
		if (*first > *high)
		{
			high = first;
		}
		++first;
	}
	return high;
}

int main()
try
{
	std::vector<std::string> myVectorOfString;
	std::string myString;
	std::cout << "Enter words, for exit enter CTRL + Z on a separate line\n";
	while (std::cin >> myString)
	{
		myVectorOfString.push_back(myString);
	}
	auto myVectorOfStringLastWord = findLast(myVectorOfString.begin(), myVectorOfString.end());
	if (myVectorOfStringLastWord != myVectorOfString.end())
	{
		std::cout << *myVectorOfStringLastWord << '\n';
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