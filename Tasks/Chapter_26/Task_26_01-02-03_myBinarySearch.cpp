#include <iostream>
#include <fstream>
#include <vector>
#include "Task_26_01-02-03_myBinarySearch.h"

int main()
try
{
	{ // 1
		std::string fileName{ "Task_26_01.txt" };
		std::cout << fileName << '\n';
		std::ifstream inputFileStream{ fileName };
		if (!inputFileStream)
		{
			throw std::runtime_error("Can't open file");
		}
		unsigned int errors = test<int>(inputFileStream);
		std::cout << "Errors: " << errors << '\n';
	}
	std::cout << "\n\n";
	{ // 2
		{
			std::string fileName{ "Task_26_02_double.txt" };
			std::cout << fileName << '\n';
			std::ifstream inputFileStream{ fileName };
			if (!inputFileStream)
			{
				throw std::runtime_error("Can't open file");
			}
			unsigned int errors = test<double>(inputFileStream);
			std::cout << "Errors: " << errors << '\n';
		}
		{
			std::string fileName{ "Task_26_02_string.txt" };
			std::cout << fileName << '\n';
			std::ifstream inputFileStream{ fileName };
			if (!inputFileStream)
			{
				throw std::runtime_error("Can't open file");
			}
			unsigned int errors = test<double>(inputFileStream);
			std::cout << "Errors: " << errors << '\n';
		}
	}
	std::cout << "\n\n";
	{ // 3
		{
			std::string fileName{ "Task_26_03_int.txt" };
			std::cout << fileName << '\n';
			std::ifstream inputFileStream{ fileName };
			if (!inputFileStream)
			{
				throw std::runtime_error("Can't open file");
			}
			unsigned int errors = test<int>(inputFileStream);
			std::cout << "Errors: " << errors << '\n';
		}
		{
			std::string fileName{ "Task_26_03_double.txt" };
			std::cout << fileName << '\n';
			std::ifstream inputFileStream{ fileName };
			if (!inputFileStream)
			{
				throw std::runtime_error("Can't open file");
			}
			unsigned int errors = test<double>(inputFileStream);
			std::cout << "Errors: " << errors << '\n';
		}
		{
			std::string fileName{ "Task_26_03_string.txt" };
			std::cout << fileName << '\n';
			std::ifstream inputFileStream{ fileName };
			if (!inputFileStream)
			{
				throw std::runtime_error("Can't open file");
			}
			unsigned int errors = test<double>(inputFileStream);
			std::cout << "Errors: " << errors << '\n';
		}
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