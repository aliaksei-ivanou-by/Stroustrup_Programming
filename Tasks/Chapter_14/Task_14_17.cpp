#ifndef TASK_14_17_STDAFX_H
#include "Task_14_17_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), x_max() - 50, y_max() - 50, "Simple_window");
	Group table;

	int start = 10;
	int delta = 135;

	table.add(new Box_text(Point(start + delta * 0, 50), "logic error"));					// 1
	table.add(new Box_text(Point(start + delta * 1, 50), "invalid argument"));				// 1.1
	table.add(new Box_text(Point(start + delta * 2, 50), "domain error"));					// 1.2
	table.add(new Box_text(Point(start + delta * 3, 50), "length error"));					// 1.3
	table.add(new Box_text(Point(start + delta * 4, 50), "out of range"));					// 1.4
	table.add(new Box_text(Point(start + delta * 5, 50), "future error"));					// 1.5

	table.add(new Box_text(Point(start + delta * 0, 100), "bad optional access"));			// 2

	table.add(new Box_text(Point(start + delta * 0, 150), "runtime error"));				// 3
	table.add(new Box_text(Point(start + delta * 1, 150), "range error"));					// 3.1
	table.add(new Box_text(Point(start + delta * 2, 150), "overflow error"));				// 3.2
	table.add(new Box_text(Point(start + delta * 3, 150), "underflow error"));				// 3.3
	table.add(new Box_text(Point(start + delta * 4, 150), "regex error"));					// 3.4
	table.add(new Box_text(Point(start + delta * 5, 150), "system error"));					// 3.5
	table.add(new Box_text(Point(start + delta * 6, 150), "tx exception"));					// 3.6
	table.add(new Box_text(Point(start + delta * 7, 150), "nonexistent local time"));		// 3.7
	table.add(new Box_text(Point(start + delta * 8, 150), "ambiguous local time"));			// 3.8
	table.add(new Box_text(Point(start + delta * 9, 150), "format error"));					// 3.9

	table.add(new Box_text(Point(start + delta * 0, 200), "bad typeid"));					// 4

	table.add(new Box_text(Point(start + delta * 0, 250), "bad cast"));						// 5
	table.add(new Box_text(Point(start + delta * 1, 250), "bad any cast"));					// 5.1

	table.add(new Box_text(Point(start + delta * 0, 300), "bad weak ptr"));					// 6

	table.add(new Box_text(Point(start + delta * 0, 350), "bad function call"));			// 7

	table.add(new Box_text(Point(start + delta * 0, 400), "bad alloc"));					// 8
	table.add(new Box_text(Point(start + delta * 1, 400), "bad array new length"));			// 8.1

	table.add(new Box_text(Point(start + delta * 0, 450), "bad exception"));				// 9

	table.add(new Box_text(Point(start + delta * 0, 500), "ios base failure"));				// 10

	table.add(new Box_text(Point(start + delta * 0, 550), "bad variant access"));			// 11

	table.set_color(Color::black);
	table.set_fill_color(Color::blue);
	win.attach(table);
	win.wait_for_button();
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