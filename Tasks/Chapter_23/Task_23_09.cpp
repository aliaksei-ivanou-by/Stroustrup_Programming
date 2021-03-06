#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>

struct bad_from_string : std::bad_cast
{
	const char* what() const
	{
		return "bad cast from string";
	}

};

template<class T>
T from_string(const std::string& s)
{
	std::istringstream is(s);
	T t;
	if (!(is >> t))
	{
		throw bad_from_string();
	}
	return t;
}

int main()
try
{
	std::string fileName = "Task_23_09.txt";
	std::ifstream inputFileStream{ fileName };
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't open file " + fileName);
	}
	
	std::string line;
	int lineno = 0;

	std::regex header{ "^[\\w\\s]+(\\t[\\w\\s]+)*$" };
	std::regex row{ "^[\\w ]+(\\t\\d+)(\\t\\d+)(\\t\\d+)$" };

	if (getline(inputFileStream, line))
	{
		std::smatch matches;
		if (!std::regex_match(line, matches, header))
		{
			throw std::runtime_error("No header");
		}
	}

	int boys = 0;
	int girls = 0;
	int curr_boy = 0;
	int curr_girl = 0;
	int curr_total = 0;

	while (getline(inputFileStream, line))
	{
		++lineno;
		std::smatch matches;
		if (!std::regex_match(line, matches, row))
		{
			std::cerr << "Wrong line " << lineno << '\n';
		}
		if (inputFileStream.eof())
		{
			std::cout << "End of file\n";
		}

		curr_boy = from_string<int>(matches[1]);
		curr_girl = from_string<int>(matches[2]);
		curr_total = from_string<int>(matches[3]);
		if (curr_boy + curr_girl != curr_total)
		{
			throw std::runtime_error("Wrong sum in the line");
		}
		std::regex total{ "Alle klasser" };
		if (std::regex_search(line, matches, total))
		{
			if (curr_boy != boys)
			{
				throw std::runtime_error("Wrong number of boys");
			}
			if (curr_girl != girls)
			{
				throw std::runtime_error("Wrong number of girls");
			}
			if (!(inputFileStream >> std::ws).eof())
			{
				throw std::runtime_error("Symbols after last line");
			}
			std::cout << "boys = " << boys << '\n';
			std::cout << "girls = " << girls << '\n';
			return 0;
		}
		boys += curr_boy;
		girls += curr_girl;
	}
	throw std::runtime_error("No total line");
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