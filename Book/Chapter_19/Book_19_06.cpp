#ifndef BOOK_19_06_STDAFX_H
#include "Book_19_06_stdafx.h"
#endif

int main(int argc, char** argv)
try
{

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