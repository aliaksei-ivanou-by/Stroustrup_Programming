#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include "Task_21_13-14-15_number_unique_words.h"

class Window_TextClean : public Window
{
public:
	Window_TextClean():
		Window{ Point{ 50, 50 }, 600, 400, "Text Analyze" },
		inboxFileName{ Point{ 75, 20 }, 450, 30, "File" },
		buttonCase1{ Point{ 75, 60 }, 450, 30, "String was used ...", cbCase1CountWord },
		buttonCase2{ Point{ 75, 100 }, 450, 30, "The most frequently used word?", cbCase2FindMostFrequentlyWord },
		buttonCase3{ Point{ 75, 140 }, 450, 30, "The longest word", cbCase3FindLongestWord },
		buttonCase4{ Point{ 75, 180 }, 450, 30, "The shortest word", cbCase4FindShortestWord },
		inboxString{ Point{ 75, 220 }, 400, 30, "Word" },
		buttonCase1Find{ Point{ 475, 220 }, 50, 30, "Find", cbCase1FindCountWord },
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
private:
	In_box inboxFileName;

	Button buttonCase1;
	In_box inboxString;
	Button buttonCase1Find;
	Button buttonCase2;
	Button buttonCase3;
	Button buttonCase4;

	Out_box outboxString;
	Out_box outboxCount;

	Out_box outboxInformation;

	static void cbCase1CountWord(Address, Address pw)
	{
		reference_to<Window_TextClean>(pw).case1CountWord();
	}
	static void cbCase1FindCountWord(Address, Address pw)
	{
		reference_to<Window_TextClean>(pw).case1FindCountWord();
	}
	static void cbCase2FindMostFrequentlyWord(Address, Address pw)
	{
		reference_to<Window_TextClean>(pw).case2FindMostFrequentlyWord();
	}
	static void cbCase3FindLongestWord(Address, Address pw)
	{
		reference_to<Window_TextClean>(pw).case3FindLongestWord();
	}
	static void cbCase4FindShortestWord(Address, Address pw)
	{
		reference_to<Window_TextClean>(pw).case4FindShortestWord();
	}

	void case1CountWord()
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
	void case1FindCountWord()
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
	void case2FindMostFrequentlyWord()
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
	void case3FindLongestWord()
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
	void case4FindShortestWord()
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

	void hideAll()
	{
		inboxString.hide();
		buttonCase1Find.hide();
		outboxString.hide();
		outboxCount.hide();
		outboxInformation.hide();
	}
};

int main(int argc, char** argv)
try
{
	Window_TextClean win;
	return gui_main();
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