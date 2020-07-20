#ifndef BOOK_16_03_STDAFX_H
#include "Book_16_03_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), 600, 400, "Simple_window");
	Menu disasters(Point(100, 100), 60, 20, Menu::horizontal, "disasters");
	load_disaster_menu(disasters);
	win.attach(disasters);
	return 0;
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