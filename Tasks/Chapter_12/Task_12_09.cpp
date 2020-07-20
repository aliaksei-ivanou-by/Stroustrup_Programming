#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	using namespace Graph_lib;
	Point point(100, 100);
	Simple_window win(point, x_max() - 200, y_max() - 200, "My window");

	Image image(Point(50, 50), "snow_cpp.gif");
	win.attach(image);
	win.set_label("C++");

	Text txt(Point(50, 320), "C++");
	win.attach(txt);

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