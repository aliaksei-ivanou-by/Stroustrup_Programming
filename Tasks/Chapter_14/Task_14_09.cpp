#ifndef TASK_14_09_STDAFX_H
#include "Task_14_09_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Point start(200, 200);
	int side = 30;
	Group white_cells;
	Group black_cells;
	win.attach(white_cells);
	win.attach(black_cells);
	for (int j = 0; j < 8; j += 2)
	{
		for (int i = 0; i < 8; i += 2)
		{
			white_cells.add(new Graph_lib::Rectangle(Point(start.x + side * i, start.y + side * j), side, side));
		}
	}
	for (int j = 1; j < 9; j += 2)
	{
		for (int i = 1; i < 9; i += 2)
		{
			white_cells.add(new Graph_lib::Rectangle(Point(start.x + side * i, start.y + side * j), side, side));
		}
	}
	white_cells.set_color(Color::black);
	white_cells.set_fill_color(Color::white);
	for (int j = 1; j < 9; j += 2)
	{
		for (int i = 0; i < 8; i += 2)
		{
			black_cells.add(new Graph_lib::Rectangle(Point(start.x + side * i, start.y + side * j), side, side));
		}
	}
	for (int j = 0; j < 8; j += 2)
	{
		for (int i = 1; i < 9; i += 2)
		{
			black_cells.add(new Graph_lib::Rectangle(Point(start.x + side * i, start.y + side * j), side, side));
		}
	}
	black_cells.set_color(Color::black);
	black_cells.set_fill_color(Color::black);
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