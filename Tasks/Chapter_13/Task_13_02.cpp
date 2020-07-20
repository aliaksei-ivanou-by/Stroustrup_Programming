#include "Task_13_02_Box.h"

int main()
try
{
	Simple_window win(Point(100, 100), x_max() - 100, y_max() - 100, "Simple_window");
	Box box1(Point(150, 150), 50, 50);
	box1.set_color(Color::black);
	Box box2(Point(220, 220), 100, 100);
	box2.set_color(Color::black);
	win.attach(box1);
	win.attach(box2);
	win.wait_for_button();
}
catch (const exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}