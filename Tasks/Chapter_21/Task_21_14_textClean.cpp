#ifndef TASK_21_14_STDAFX_H
#include "Task_21_14_stdafx.h"
#include "Task_21_14_textClean.h"
#endif

void fileOpen(std::ifstream& inputFileStream, const std::string& fileName)
{
	inputFileStream = std::ifstream(fileName);
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't open file");
	}
}

void textCleanToLower(std::ifstream& inputFileStream, std::ostringstream& outputStringStream, char& ch)
{
	while (inputFileStream.get(ch))
	{
		if (ispunct(ch) && ch != '\'')
		{
			ch = ' ';
		}
		outputStringStream << char(tolower(ch));
	}
}

void textCleanRemoveAbbreviations(std::istringstream& inputStringStream, std::map<std::string, int>& data, std::string& str)
{
	while (inputStringStream >> str)
	{
		if (str == "won't") // remove won't - insert "will" and "not"
		{
			++data["will"];
			++data["not"];
		}
		else
		{
			if (str == "can't") // remove "can't" - insert "cannot"
			{
				++data["cannot"];
			}
			else
			{
				if (str.size() >= 3 && *(str.end() - 2) == '\'') // "'m", "'s", "'d", "'t"
				{
					switch (str.back())
					{
					case 'm': // remove "'m" - insert "am"
					{
						++data["am"];
						break;
					}
					case 's': // remove "'s" - insert "is"
					{
						++data["is"];
						break;
					}
					case 'd': // remove "'d"  - insert "would"
					{
						++data["would"];
						break;
					}
					case 't': // remove "'t" - insert "not" (as "don't, wouldn't, etc") and original str without "'t"
					{
						++data["not"];
						++data[str.substr(0, str.size() - 3)];
						break;
					}
					}
				}
				else
				{
					if (str.size() >= 4 && *(str.end() - 3) == '\'') // "'l", "'r", "'v"
					{
						switch (*(str.end() - 2))
						{
						case 'l': // remove "'l" - insert "will"  and original str without "'l"
						{
							++data["will"];
							++data[str.substr(0, str.size() - 3)];
							break;
						}
						case 'r': // remove "'r" - insert "are" and original str without "'r"
						{
							++data["are"];
							++data[str.substr(0, str.size() - 3)];
							break;
						}
						case 'v': // remove "'v" - insert "have" and original str without "'v"
						{
							++data["have"];
							++data[str.substr(0, str.size() - 3)];
							break;
						}
						}
					}
					else
					{
						++data[str]; // insert other cases
					}
				}
			}
		}
	}
}

void textCleanRemovePlurals(std::map<std::string, int>& data)
{
	for (auto i = data.begin(); i != data.end(); ++i)
	{
		auto next = i;
		++next;
		while (next != data.end())
		{
			if (next->first == i->first + "s" && i->first.size() > 1)
			{
				next = data.erase(next); // remove word if "word+s" is found
			}
			else
			{
				++next;
			}
		}
	}
}

std::map<std::string, int> textClean(const std::string& fileName)
{
	std::ifstream inputFileStream;
	fileOpen(inputFileStream, fileName);

	char ch;
	std::ostringstream outputStringStream;
	textCleanToLower(inputFileStream, outputStringStream, ch);

	std::istringstream inputStringStream(outputStringStream.str());
	std::string str;
	std::map<std::string, int> data;
	textCleanRemoveAbbreviations(inputStringStream, data, str);
	textCleanRemovePlurals(data);
	return data;
}