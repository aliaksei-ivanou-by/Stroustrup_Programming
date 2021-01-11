#ifndef TASK_23_10_STDAFX_H
#define TASK_23_10_STDAFX_H

#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
#include <map>
#include <numeric>

#endif

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

struct students
{
	int boys;
	int girls;
	int total;
};

void dataMerge(
	const std::string& fileNameInput,
	const std::string& fileNameOutput,
	std::map<char, students>& map)
{
	std::ifstream inputFileStream{ fileNameInput };
	if (!inputFileStream)
	{
		throw("Can't open file");
	}
	std::ofstream outputFileStream{ fileNameOutput };
	if (!outputFileStream)
	{
		throw("Can't open file");
	}

	std::regex regexHeader{ "^[KLASSE\\s]+(\\t[\\w\\s]+)*$" };
	std::regex regexRow{ "^[\\w\\s]+(\\t[\\d]+)(\\t[\\d]+)(\\t[\\d]+)$" };
	std::regex regexFooter{ "(Alle klasser)(\\t\\d+)(\\t\\d+)(\\t\\d+)$" };

	std::string lineHeader;
	std::string lineRow;
	std::string lineFooter;
	std::smatch matches;

	int lineRowNumber = 0;
	int curr_boy;
	int curr_girl;
	int curr_total;
	int total_boys;
	int total_girls;
	int total_total;

	while (getline(inputFileStream, lineRow))
	{
		++lineRowNumber;

		if (std::regex_search(lineRow, matches, regexHeader))
		{
			lineHeader = lineRow;
		}
		if (std::regex_match(lineRow, matches, regexRow))
		{
			char key = matches[0].str()[0];
			curr_boy = from_string<int>(matches[1]);
			curr_girl = from_string<int>(matches[2]);
			curr_total = from_string<int>(matches[3]);
			if (curr_boy + curr_girl != curr_total)
			{
				throw("Wrong sum in the line");
			}
			if (isdigit(key) || key == 'R')
			{
				map[key].boys += curr_boy;
				map[key].girls += curr_girl;
				map[key].total += curr_total;
			}
		}
		else
		{
			std::cerr << "Wrong line " << lineRowNumber << '\n';
		}
		if (std::regex_search(lineRow, matches, regexFooter))
		{
			lineFooter = lineRow;

			total_boys = from_string<int>(matches[2]);
			total_girls = from_string<int>(matches[3]);
			total_total = from_string<int>(matches[4]);

			int boys = std::accumulate(map.begin(),
				map.end(),
				0,
				[&](int total, const std::map< char, students >::value_type& data)
				{ return total + data.second.boys; });
			if (total_boys != boys)
			{
				throw("Wrong number of boys");
			}

			int girls = std::accumulate(map.begin(),
				map.end(),
				0,
				[&](int total, const std::map< char, students >::value_type& data)
				{ return total + data.second.girls; });
			if (total_girls != girls)
			{
				throw("Wrong number of girls");
			}

			int total = std::accumulate(map.begin(),
				map.end(),
				0,
				[&](int total, const std::map< char, students >::value_type& data)
				{ return total + data.second.total; });
			if (total_total != total)
			{
				throw("Wrong number of total people");
			}

			if (!(inputFileStream >> std::ws).eof())
			{
				throw("Symbols after last line");
			}
		}
		if (inputFileStream.eof())
		{
			std::cerr << "End of file\n";
		}
	}

	outputFileStream << lineHeader << '\n';

	for (const auto& i : map)
	{
		outputFileStream << i.first << '\t' << i.second.boys << '\t' << i.second.girls << '\t' << i.second.total << '\n';
	}
	outputFileStream << lineFooter << '\n';

	inputFileStream.close();
	outputFileStream.close();
}