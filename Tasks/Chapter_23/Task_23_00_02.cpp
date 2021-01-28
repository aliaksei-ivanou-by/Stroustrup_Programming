#ifndef TASK_23_00_02_STDAFX_H
#include "Task_23_00_02_stdafx.h"
#endif

int main()
try
{
	std::cout << "\nUnix\n";
	std::cout << "UNIX is an operating system developed in the Bell Laboratories " <<
		"of AT& Tand is an example a multi - tasking, " <<
		"multi - user operating system.It provides its users with : " <<
		"program development tools; electronic communications facilities, " <<
		"such as an electronic mail; text editorsand text formatters. " <<
		"There are also many development tools available as standard within the UNIX operating system " <<
		"that other operating systems require as add - ons.\n";

	std::cout << "\nAWK\n";
	std::cout << "AWK is a programming languageand a POSIX specification " <<
		"that originated at AT& T Bell Laboratories in 1977. " <<
		"Its name comes from the initials of its designers : " <<
		"Aho, Weinberger, and Kernighan.awk features user - " <<
		"defined functions, multiple input streams, TCP / IP networking access, " <<
		"and a rich set of regular expressions. " <<
		"It's often used to process raw text files, " <<
		"interpreting the data it finds as records and fields to be manipulated by the user.\n";

	std::cout << "At its most basic, awk searches files for some unit of text " <<
		"(usually lines terminated with an end - of - line character) " <<
		"containing some user - specified pattern. " <<
		"When a line matches one of the patterns, " <<
		"awk performs some set of user - defined actions on that line, " <<
		"then processes input lines until the end of the input files.\n";

	std::cout << "\nPERL\n";
	std::cout << "Perl is a general - purpose programming language " <<
		"originally developed for text manipulation and " <<
		"now used for a wide range of tasks including system administration, " <<
		"web development, network programming, GUI development, and more.\n";

	std::cout << "\nPHP\n";
	std::cout << "PHP is a general - purpose scripting language " <<
		"especially suited to web development. It was originally created by Danish - " <<
		"Canadian programmer Rasmus Lerdorf in 1994. " <<
		"The PHP reference implementation is now produced by The PHP Group. " <<
		"PHP originally stood for Personal Home Page, " <<
		"but it now stands for the recursive initialism PHP : Hypertext Preprocessor.\n";

	std::cout << "\nWG21\n";
	std::cout << "The ISO C++ committee is called WG21, officially " <<
		"ISO / IEC JTC1 (Joint Technical Committee 1) / SC22 (Subcommittee 22) / WG21 (Working Group 21). " <<
		"WG21 was formed in 1990 - 91, and consists of accredited experts " <<
		"from member nations of ISO / IEC JTC1 / SC22 who are interested in C++ work.\n";

	std::cout << "\ngrep\n";
	std::cout << "grep is a command - line utility for searching plain - " <<
		"text data sets for lines that match a regular expression. " <<
		"Its name comes from the ed command g/re/p " <<
		"(globally search for a regular expressionand print matching lines), " <<
		"which has the same effect.[3][4] grep was originally developed " <<
		"for the Unix operating system, but later available for all Unix - " <<
		"like systems and some others such as OS - 9.\n";

	std::cout << "\nJohn Maddock\n";
	std::cout << "John Maddock is a software developer from England and " << 
		"holds a PhD in Chemistry, but found that computers " << 
		"smell less and explode less often!John is the author of the regex++ " <<
		"regular expression package, has an almost pathological " <<
		"interest in anything that \"can't be done\"\n";
	
	std::cout << "\nBoost(C++ libraries)\n";
	std::cout << "Boost is a set of libraries for the C++ programming language " <<
		"that provides support for tasksand structures such as linear algebra, " <<
		"pseudorandom number generation, multithreading, image processing, " <<
		"regular expressions, and unit testing. " <<
		"It contains 164 individual libraries( as of version 1.75).\n";
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