#include "Simple_window.h"
#include "Graph.h"
#include "Task_13_03_Arrow.h"

int main()
try
{
	const Point p(100, 100);
	Simple_window win(p, x_max() - 600, y_max() - 400, "Simple_window");
	Arrow arrow1(Point(100, 100), Point(200, 200));
	arrow1.set_color(Color::yellow);
	win.attach(arrow1);
	Arrow arrow2(Point(150, 200), Point(300, 200));
	arrow2.set_color(Color::red);
	win.attach(arrow2);
	Arrow arrow3(Point(200, 150), Point(250, 150));
	arrow3.set_color(Color::green);
	win.attach(arrow3);
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