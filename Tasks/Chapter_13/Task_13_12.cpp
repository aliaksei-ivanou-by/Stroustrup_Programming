#include "Simple_window.h"
#include "Graph.h"

const double pi = 3.1415926;

int main()
try
{
	using namespace Graph_lib;
	Point p(50, 50);
	Simple_window win(p, x_max() - 400, y_max() - 100, "My window");
	const Point c_center(400, 300);
	Circle c(c_center, 150);
	win.attach(c);
	win.wait_for_button();
	Mark x(Point(c_center.x + c.radius(), c_center.y), 'x');
	win.attach(x);
	double alpha = pi / 12;
	double beta = 0;
	while (beta < 2 * pi)
	{
		beta += alpha;
		int dx = round(c.radius() * cos(beta) - c.radius() * cos(beta - alpha));
		int dy = round(c.radius() * sin(beta) - c.radius() * sin(beta - alpha));
		x.move(dx, dy);
		win.wait_for_button();
	}
	return 0;
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