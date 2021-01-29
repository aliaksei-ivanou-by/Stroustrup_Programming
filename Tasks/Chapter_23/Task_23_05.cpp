#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <regex>
#include <chrono>
#include "Task_23_Mail_file.h"

void testMap()
{
	auto timeVectorStart = std::chrono::system_clock::now();
	std::string fileName("Task_23_05.txt");
	Mail_file mailFile(fileName);
	std::multimap<std::string, const Message*> sender;

	for (auto i = mailFile.begin(); i != mailFile.end(); ++i)
	{
		const Message& message = *i;
		std::string s;

		if (find_from_addr(&message, s))
		{
			sender.insert(std::make_pair(s, &message));
		}
	}
	auto timeVectorFinish = std::chrono::system_clock::now();
	std::cout << "\nTime for map is\t" <<
		std::chrono::duration_cast<std::chrono::milliseconds>(timeVectorFinish - timeVectorStart).count() << "ms";
	std::cout << "\n";
}

void testUnorderedMap()
{
	auto timeVectorStart = std::chrono::system_clock::now();
	std::string fileName("Task_23_05.txt");
	Mail_file mailFile(fileName);
	std::unordered_multimap<std::string, const Message*> sender;

	for (auto i = mailFile.begin(); i != mailFile.end(); ++i)
	{
		const Message& message = *i;
		std::string s;

		if (find_from_addr(&message, s))
		{
			sender.insert(std::make_pair(s, &message));
		}
	}
	auto timeVectorFinish = std::chrono::system_clock::now();
	std::cout << "\nTime for unordered_multimap is\t" <<
		std::chrono::duration_cast<std::chrono::milliseconds>(timeVectorFinish - timeVectorStart).count() << "ms";
	std::cout << "\n";
}

int main()
try
{
	testMap();
	testUnorderedMap();
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