#ifndef TASK_14_01_STDAFX_H
#include "Task_14_01_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	// 1
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Smiley head1(Point(300, 150), 50);
	win.attach(head1);
	Frowny head2(Point(600, 150), 50);
	win.attach(head2);
	win.wait_for_button();
	// 2
	Smiley_Hat head3(Point(300, 350), 50);
	win.attach(head3);
	Frowny_Hat head4(Point(600, 350), 50);
	win.attach(head4);
	win.wait_for_button();
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