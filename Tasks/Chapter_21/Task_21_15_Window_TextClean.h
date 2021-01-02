#ifndef TASK_21_15_WINDOW_TEXTCLEAN_H
#define TASK_21_15_WINDOW_TEXTCLEAN_H

#ifndef TASK_21_15_STDAFX_H
#include "Task_21_15_stdafx.h"
#endif

class Window_TextClean : public Window
{
public:
	Window_TextClean();
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

	static void cbCase1CoundWord(Address, Address pw);
	static void cbCase1FindCoundWord(Address, Address pw);
	static void cbCase2FindMostFrequenlyWord(Address, Address pw);
	static void cbCase3FindLongestWord(Address, Address pw);
	static void cbCase4FindShortestWord(Address, Address pw);

	void case1CoundWord();
	void case1FindCoundWord();
	void case2FindMostFrequenlyWord();
	void case3FindLongestWord();
	void case4FindShortestWord();

	void hideAll();
};

#endif