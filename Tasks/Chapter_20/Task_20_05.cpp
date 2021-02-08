#include <iostream>
#include <vector>

template<typename T>
std::istream& operator>>(std::istream& inputStream, std::vector<T>& vector)
{
	std::cout << "(Example : { 1 2 3 })\n";
	char ch;
	T temp;
	inputStream >> ch;
	while (true)
	{
		inputStream >> ch;
		if (inputStream && ch == '}')
		{
			return inputStream;
		}
		else
		{
			inputStream.unget();
		}
		inputStream >> temp;
		if (inputStream)
		{
			vector.push_back(temp);
		}
	}
	return inputStream;
}

template<typename T>
std::ostream& operator<<(std::ostream& outputStream, const std::vector<T>& vector)
{
	outputStream << "{ ";
	for (auto& i : vector)
	{
		outputStream << i << ' ';
	}
	outputStream << "}";
	return outputStream;
}

int main()
try
{
	std::vector<int> vectorInt;
	std::vector<double> vectorDouble;

	std::cout << "Enter vectorInt : ";
	std::cin >> vectorInt;
	std::cout << "vectorInt is : " << vectorInt;

	std::cout << '\n';

	std::cout << "Enter vectorDouble : ";
	std::cin >> vectorDouble;
	std::cout << "vectorDouble is : " << vectorDouble;
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