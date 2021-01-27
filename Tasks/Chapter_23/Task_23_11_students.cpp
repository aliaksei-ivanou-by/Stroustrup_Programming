#ifndef TASK_23_11_STDAFX
#include "Task_23_11_stdafx.h"
#include "Task_23_11_students.h"
#endif

const char* bad_from_string::what() const
{
	return "bad cast from string";
}

void dataMerge(
	const std::string& fileNameInput,
	const std::string& fileNameOutput,
	std::map<char, students>& map)
{
	std::ifstream inputFileStream{ fileNameInput };
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't open file");
	}
	std::ofstream outputFileStream{ fileNameOutput };
	if (!outputFileStream)
	{
		throw std::runtime_error("Can't open file");
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
				throw std::runtime_error("Wrong sum in the line");
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
				throw std::runtime_error("Wrong number of boys");
			}

			int girls = std::accumulate(map.begin(),
				map.end(),
				0,
				[&](int total, const std::map< char, students >::value_type& data)
				{ return total + data.second.girls; });
			if (total_girls != girls)
			{
				throw std::runtime_error("Wrong number of girls");
			}

			int total = std::accumulate(map.begin(),
				map.end(),
				0,
				[&](int total, const std::map< char, students >::value_type& data)
				{ return total + data.second.total; });
			if (total_total != total)
			{
				throw std::runtime_error("Wrong number of total people");
			}

			if (!(inputFileStream >> std::ws).eof())
			{
				throw std::runtime_error("Symbols after last line");
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

void getStatistics(std::map<char, students>& map, const std::string& fileName)
{
	std::ofstream outputFileStream{ fileName };
	if (!outputFileStream)
	{
		throw std::runtime_error("Can't open file");
	}
	for (auto i = map.begin(); i != map.end(); ++i)
	{
		char d = i->first;
		if (isdigit(d))
		{
			outputFileStream << d << '\t' << std::setw(5) << i->second.total << '\t';
			for (int j = 0; j < i->second.total; ++j)
			{
				outputFileStream << "#";
			}
			outputFileStream << '\n';
		}
	}
	outputFileStream.close();
}