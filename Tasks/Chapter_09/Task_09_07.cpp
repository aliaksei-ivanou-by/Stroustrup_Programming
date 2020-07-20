#include "iostream"
#include "Task_09_07_Lib.h"

int main()
{
	Lib::Book book(Lib::ISBN(9780, 4393, 5807, 'x'),
	        "Harry Potter and the Order of the Phoenix",
	        "Rowling, J.K.",
	        2003,
			Lib::Book::children,
	        false);
	std::cout<<book;
	return 0;
}
