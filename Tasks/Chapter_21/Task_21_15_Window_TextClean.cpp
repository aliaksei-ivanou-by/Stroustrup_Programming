#ifndef TASK_21_15_STDAFX_H
#include "Task_21_15_stdafx.h"
#include "Task_21_15_Window_TextClean.h"
#include "Task_21_15_TextClean.h"
#endif

Window_TextClean::Window_TextClean():
	Window{ Point{ 50, 50 }, 600, 400, "Text Analyze" },
	inboxFileName{ Point{ 75, 20 }, 450, 30, "File" },
	buttonCase1{ Point{ 75, 60 }, 450, 30, "String was used ...", cbCase1CoundWord },
	buttonCase2{ Point{ 75, 100 }, 450, 30, "The most frequently used word?", cbCase2FindMostFrequenlyWord },
	buttonCase3{ Point{ 75, 140 }, 450, 30, "The longest word", cbCase3FindLongestWord },
	buttonCase4{ Point{ 75, 180 }, 450, 30, "The shortest word", cbCase4FindShortestWord },
	inboxString{ Point{ 75, 220 }, 400, 30, "Word" },
	buttonCase1Find{ Point{ 475, 220 }, 50, 30, "Find", cbCase1FindCoundWord },
	outboxString{ Point{ 75, 260 }, 450, 30, "Word" },
	outboxCount{ Point{ 75, 300 }, 450, 30, "Count" },
	outboxInformation{ Point{ 75, 340 }, 450, 30, "" }
{
	attach(inboxFileName);
	attach(buttonCase1);
	attach(inboxString);
	attach(buttonCase1Find);
	attach(buttonCase2);
	attach(buttonCase3);
	attach(buttonCase4);
	attach(outboxString);
	attach(outboxCount);
	attach(outboxInformation);

	inboxString.hide();
	buttonCase1Find.hide();
	outboxString.hide();
	outboxCount.hide();
	outboxInformation.hide();
}

void Window_TextClean::cbCase1CoundWord(Address, Address pw)
{
	reference_to<Window_TextClean>(pw).case1CoundWord();
}

void Window_TextClean::cbCase1FindCoundWord(Address, Address pw)
{
	reference_to<Window_TextClean>(pw).case1FindCoundWord();
}

void Window_TextClean::cbCase2FindMostFrequenlyWord(Address, Address pw)
{
	reference_to<Window_TextClean>(pw).case2FindMostFrequenlyWord();
}

void Window_TextClean::cbCase3FindLongestWord(Address, Address pw)
{
	reference_to<Window_TextClean>(pw).case3FindLongestWord();
}

void Window_TextClean::cbCase4FindShortestWord(Address, Address pw)
{
	reference_to<Window_TextClean>(pw).case4FindShortestWord();
}

void Window_TextClean::case1CoundWord()
try
{
	hideAll();

	inboxString.show();
	buttonCase1Find.show();
}
catch (...)
{
	hideAll();
	outboxInformation.put("Error");
	outboxInformation.show();
}

void Window_TextClean::case1FindCoundWord()
try
{
	std::string fileName = inboxFileName.get_string();
	std::map<std::string, int> words = textClean(fileName);
	std::string temp = inboxString.get_string();
	outboxString.put(temp);
	outboxCount.put(std::to_string(words[temp]));
	outboxString.show();
	outboxCount.show();
	inboxString.hide();
	buttonCase1Find.hide();
}
catch (...)
{
	hideAll();
	outboxInformation.put("Error");
	outboxInformation.show();
}

void Window_TextClean::case2FindMostFrequenlyWord()
try
{
	hideAll();

	std::string fileName = inboxFileName.get_string();
	std::map<std::string, int> words = textClean(fileName);

	auto temp = words.begin();
	for (auto i = words.begin(); i != words.end(); ++i)
	{
		if (i->second > temp->second)
		{
			temp = i;
		}
	}
	outboxString.put(temp->first);
	outboxCount.put(std::to_string(temp->second));
	outboxString.show();
	outboxCount.show();
}
catch (...)
{
	hideAll();
	outboxInformation.put("Error");
	outboxInformation.show();
}

void Window_TextClean::case3FindLongestWord()
try
{
	hideAll();

	std::string fileName = inboxFileName.get_string();
	std::map<std::string, int> words = textClean(fileName);

	auto temp = words.begin();
	for (auto i = words.begin(); i != words.end(); ++i)
	{
		if (i->first.size() > temp->first.size())
		{
			temp = i;
		}
	}
	outboxString.put(temp->first);
	outboxCount.put(std::to_string(temp->second));
	outboxString.show();
	outboxCount.show();

}
catch (...)
{
	hideAll();
	outboxInformation.put("Error");
	outboxInformation.show();
}

void Window_TextClean::case4FindShortestWord()
try
{
	hideAll();

	std::string fileName = inboxFileName.get_string();
	std::map<std::string, int> words = textClean(fileName);

	auto temp = words.begin();
	for (auto i = words.begin(); i != words.end(); ++i)
	{
		if (i->first.size() < temp->first.size())
		{
			temp = i;
		}
	}
	outboxString.put(temp->first);
	outboxCount.put(std::to_string(temp->second));
	outboxString.show();
	outboxCount.show();
}
catch (...)
{
	hideAll();
	outboxInformation.put("Error");
	outboxInformation.show();
}

void Window_TextClean::hideAll()
{
	inboxString.hide();
	buttonCase1Find.hide();
	outboxString.hide();
	outboxCount.hide();
	outboxInformation.hide();
}