#include <iostream>
#include <fstream>
#include <map>

int main()
try
{
	const std::string fileNameInput{ "Task_21_08.txt" };
	std::ifstream inputFileStream{ fileNameInput };
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't read file" + fileNameInput);
	}

	std::map<std::string, int> words;
	for (std::string i; inputFileStream >> i; )
	{
		++words[i];
	}

	std::multimap<int, std::string> frequencies;
	for (const auto& w : words)
	{
		frequencies.insert(std::pair<int, std::string>(w.second, w.first));
	}

	for (auto i = frequencies.begin(); i != frequencies.end(); ++i)
	{
		std::cout << i->first <<": "<< i->second << '\n';
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