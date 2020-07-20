#include "iostream"
#include "Task_09_06_Lib.h"

int main()
{
	Lib::Book book1(Lib::ISBN(9780,4393,5807,'1'),
	        "Harry Potter and the Order of the Phoenix",
	        "Rowling, J.K.",
	        2003,
	        false);
	std::cout<<"Book 1: \n"<<book1;
	Lib::Book book2(Lib::ISBN(9780,4393,5807,'1'),
		        "Harry Potter and the Order of the Phoenix",
		        "Rowling, J.K.",
		        2003,
		        false);
	std::cout<<"Book 2: \n"<<book2;
	Lib::Book book3(Lib::ISBN(9780,4393,5807,'1'),
		        "Harry Potter and the Order of the Phoenix",
		        "Rowling, J.K.",
		        2003,
		        false);
	std::cout<<"Book 3: \n"<<book3;
	Lib::Book book4(Lib::ISBN(9780,4393,5807,'x'),
		        "Harry Potter and the Order of the Phoenix",
		        "Rowling, J.K.",
		        2003,
		        false);
	std::cout<<"Book 4: \n"<<book4;
	std::cout<<"\n";
	if (book1==book2)
		std::cout<<"Books 1 and 2 are equal\n";
	else
		std::cout<<"Books 1 and 2 aren't equal\n";
	if (book3!=book4)
			std::cout<<"Books 3 and 4 aren't equal\n";
		else
			std::cout<<"Books 3 and 4 are equal\n";
	return 0;
}
