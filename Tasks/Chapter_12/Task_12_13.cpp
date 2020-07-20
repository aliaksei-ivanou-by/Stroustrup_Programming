#include "Simple_window.h"
#include "Graph.h"
#include <vector>
#include <cmath>

constexpr double pi = 3.14159;

double sgn(double d)
{
	if (d > 0)
		return 1;
	else
		if (d < 0)
			return -1;
		else 
			return 0;
}

int main()
try
{
	int a = 2;
	int b = 2;
	double m = 0.5;
	double n = 0.5;
	int N = 50;

	a = 100 * a;
	b = 100 * b;

	Point p(300, 25);
	Simple_window win(p, a * 2.5, b * 2.5, "Super_ellipse");

	vector<Point> points;

	for (double angle = 0; angle < 2 * pi; angle += 2 * pi / N)
	{
		double x = pow(abs(cos(angle)), 2 / m) * a * sgn(cos(angle)) + a + 10;
		double y = pow(abs(sin(angle)), 2 / n) * b * sgn(sin(angle)) + b + 10;
		points.push_back(Point(x, y));
	}

	Closed_polyline super_ellipse;
	for (int i = 0; i < points.size(); ++i)
		super_ellipse.add(points[i]);
	super_ellipse.set_style(Line_style(Line_style::solid, 4));
	win.attach(super_ellipse);
	win.wait_for_button();

	Open_polyline line1;
	for (int i = 0; i < points.size() / 4; ++i)
	{
		line1.add(points[i]);
		for (int j = i; j < points.size(); ++j)
		{
			if (i != j)
			{
				line1.add(points[j]);
				line1.add(points[i]);
			}
		}
	}
	line1.set_color(Color::green);
	win.attach(line1);
	win.wait_for_button();

	Open_polyline line2;
	for (int i = points.size() / 4; i < points.size() / 2; ++i)
	{
		line2.add(points[i]);
		for (int j = i; j < points.size(); ++j)
		{
			if (i != j)
			{
				line2.add(points[j]);
				line2.add(points[i]);
			}
		}
	}
	line2.set_color(Color::blue);
	win.attach(line2);
	win.wait_for_button();

	Open_polyline line3;
	for (int i = points.size() / 2; i < 3 * points.size() / 4; ++i)
	{
		line3.add(points[i]);
		for (int j = i; j < points.size(); ++j)
		{
			if (i != j)
			{
				line3.add(points[j]);
				line3.add(points[i]);
			}
		}
	}
	line3.set_color(Color::yellow);
	win.attach(line3);
	win.wait_for_button();

	Open_polyline line4;
	for (int i = 3 * points.size() / 4; i < points.size(); ++i)
	{
		line4.add(points[i]);
		for (int j = i; j < points.size(); ++j)
		{
			if (i != j)
			{
				line4.add(points[j]);
				line4.add(points[i]);
			}
		}
	}
	line4.set_color(Color::white);
	win.attach(line4);
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