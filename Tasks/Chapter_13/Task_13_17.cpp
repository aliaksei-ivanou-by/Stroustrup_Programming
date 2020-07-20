#include "Task_13_08_Regular_hexagon.h"
#include <ctime>

int main()
try
{
	srand(time(NULL));
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Vector_ref<Regular_hexagon> v_h;
	int r = 30;
	for (int i = 0; i < 48; ++i)
	{
		for (int j = 0; j < 24; ++j)
		{
			int x = j * r * 3;
			int y = i * sin(60 * pi / 180) * r;
			if (i % 2 == 1)
			{
				x += r + cos(60 * pi / 180) * r;
			}
			v_h.push_back(new Regular_hexagon(Point(x, y), r));
			v_h[v_h.size() - 1].set_fill_color(Color(rand() % 16));
			win.attach(v_h[v_h.size() - 1]);
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