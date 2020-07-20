#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Vector_ref<Graph_lib::Rectangle> vr;
	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			vr.push_back(new Graph_lib::Rectangle(Point(i * 20, j * 20), 20, 20));
			vr[vr.size() - 1].set_fill_color(Color(i * 16 + j));
			vr[vr.size() - 1].set_color(Graph_lib::Color::invisible);
			win.attach(vr[vr.size() - 1]);
		}
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