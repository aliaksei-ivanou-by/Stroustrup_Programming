#include "Task_13_18_Poly.h"

int main()
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	// OK
	vector<Point> v1;
	v1.push_back(Point(200, 200));
	v1.push_back(Point(300, 200));
	v1.push_back(Point(450, 250));
	v1.push_back(Point(400, 300));
	v1.push_back(Point(200, 300));
	Poly p1(v1);
	p1.set_color(Color::black);
	win.attach(p1);
	win.wait_for_button();
	// not OK
	vector<Point> v2;
	v2.push_back(Point(500, 200));
	v2.push_back(Point(600, 200));
	v2.push_back(Point(750, 250));
	v2.push_back(Point(700, 300));
	v2.push_back(Point(500, 300));
	v2.push_back(Point(550, 150));
	Poly p2(v2);
	p2.set_color(Color::red);
	win.attach(p2);
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