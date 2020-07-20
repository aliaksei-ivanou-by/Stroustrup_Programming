#include "iostream"
#include "Task_09_05_Lib.h"

int main()
{
	Lib::Book book(Lib::ISBN(9780,4393,5807,'1'),
	        "Harry Potter and the Order of the Phoenix",
	        "Rowling, J.K.",
	        2003,
	        false);
	std::cout<<"Title: "<<book.title()<<"\n";
	std::cout<<"Author: "<<book.author()<<"\n";
	std::cout<<"Copyright date: "<<book.cop_date()<<"\n";
	std::cout<<"Checked out?: "<<book.check_out()<<"\n";
	return 0;
}
