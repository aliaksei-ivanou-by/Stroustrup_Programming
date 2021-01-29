#include <iostream>
#include <fstream>
#include <string>
#include <regex>

bool checkBankCard(const std::sub_match<std::string::const_iterator>& cardMatch)
{
	std::string card = cardMatch.str();
	int len = static_cast<int>(card.length()) - 1;
	int number = 0;
	int sum = 0;
	for (int i = len; i >= 0; i--)
	{
		number = card[i] - '0';
		if (i % 2 == 0)
		{
			number *= 2;
			if (number > 9)
			{
				number -= 9;
			}
		}
		sum += number;
	}
	if (sum % 10 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool findBankCards(const std::string& line, std::match_results<std::string::const_iterator>& m)
{
	std::regex card{ R"([\d]{13,19})" };
	return std::regex_search(line, m, card);
}

int main()
try
{
	std::string fileName = "Task_23_07.txt";
	std::ifstream inputFileStream{ fileName };
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't read file");
	}

	int lineno = 0;
	std::smatch matches;
	std::string line;
	while (inputFileStream)
	{
		++lineno;
		std::getline(inputFileStream, line);
		if (findBankCards(line, matches) && checkBankCard(matches[0]))
		{
			std::cout << lineno << ": " << line << '\n';
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