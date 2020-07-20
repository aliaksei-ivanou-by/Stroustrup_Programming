#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	// 1
	Point p(100, 100);
	Simple_window win(p, 1000, 800, "Simple_window");
	win.wait_for_button();
	// 2
	int x_size = 800;
	int y_size = 800;
	int x_n = 8;
	int y_n = 8;
	Lines grid;
	for (int x = x_size / x_n; x <= x_size; x += x_size / x_n)
	{
		grid.add(Point(x, 0), Point(x, y_size));
	}
	for (int y = y_size / y_n; y < y_size; y += y_size / y_n)
	{
		grid.add(Point(0, y), Point(x_size, y));
	}
	win.attach(grid);
	win.wait_for_button();
	// 3
	Vector_ref<Graph_lib::Rectangle> vr;
	for (int i = 0; i < 8; ++i)
	{
		vr.push_back(new Graph_lib::Rectangle(Point((i * x_size / x_n), (i * y_size / y_n)), 
													(x_size / x_n + 1), (y_size / y_n + 1)));
		vr[vr.size() - 1].set_fill_color(Color::red);
		win.attach(vr[vr.size() - 1]);
	}
	win.wait_for_button();
	// 4
	Image image1(Point(300, 0), "image.jpg");
	image1.set_mask(Point(200, 0), 200, 200);
	win.attach(image1);
	Image image2(Point(400, 200), "image.jpg");
	image2.set_mask(Point(200, 0), 200, 200);
	win.attach(image2);
	Image image3(Point(200, 500), "image.jpg");
	image3.set_mask(Point(200, 0), 200, 200);
	win.attach(image3);
	win.wait_for_button();
	// 5
	Image image(Point(0, 0), "snow_cpp.gif");
	image.set_mask(Point(0, 0), 100, 100);
	win.attach(image);
	win.wait_for_button();
	int delta_x = x_size / x_n;
	int delta_y = y_size / y_n;
	for (int j = 0; j < y_n / 2; j++)
	{
		for (int i = 0; i < x_n - 1; i++)
		{
			image.move(delta_x, 0);
			win.wait_for_button();
		}
		image.move(0, delta_y);
		win.wait_for_button();
		for (int i = x_n - 1; i > 0; i--)
		{
			image.move(-delta_x, 0);
			win.wait_for_button();
		}
		if (j != y_n / 2 - 1)
		{
			image.move(0, delta_y);
			win.wait_for_button();
		}
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