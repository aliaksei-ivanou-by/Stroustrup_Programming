#include "Task_13_05_ConPoints.h"

int main()
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Graph_lib::Ellipse ellipse(Point(300, 200), 150, 100);
	win.attach(ellipse);
	win.wait_for_button();
	Lines axes;
	axes.add(Point(ellipse.center().x - 200, ellipse.center().y), 
		Point(ellipse.center().x + 200, ellipse.center().y));
	axes.add(Point(ellipse.center().x, ellipse.center().y - 150), 
		Point(ellipse.center().x, ellipse.center().y + 150));
	win.attach(axes);
	win.wait_for_button();
	Mark f1(ellipse.focus1(), 'f');
	win.attach(f1);
	Mark f2(ellipse.focus2(), 'f');
	win.attach(f2);
	win.wait_for_button();
	Point point(sw(ellipse));
	Mark m(point, 'x');
	win.attach(m);
	win.wait_for_button();
	Lines line;
	line.add(ellipse.focus1(), point);
	line.add(point, ellipse.focus2());
	win.attach(line);
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