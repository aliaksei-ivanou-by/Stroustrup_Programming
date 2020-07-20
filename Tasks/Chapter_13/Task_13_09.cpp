#include "Task_13_09_Regular_hexagon.h"

int main()
try
{
	srand(time(0));
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Graph_lib::Vector_ref<Regular_hexagon> vr = hexagons(Point(200, 200), 40, 5, 5);
	for (int i = 0; i < vr.size(); i++)
	{
		vr[i].set_fill_color(1 + rand() % 255);
		win.attach(vr[i]);
	}
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