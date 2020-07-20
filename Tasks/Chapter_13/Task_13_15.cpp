#include "Task_13_14_Right_triangle.h"

int main()
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	int s1 = 25;
	int s2 = 25;
	int x_max = 600;
	int y_max = 400;
	Vector_ref<Right_triangle> v_t_tile;
	for (int i = 0; i < y_max / s2; ++i)
	{
		int y = i * s2 + s2;
		for (int j = 0; j < x_max / s1; ++j)
		{
			int x = j * s1;
			v_t_tile.push_back(new Right_triangle(Point(x, y), s1, s2));
			win.attach(v_t_tile[v_t_tile.size() - 1]);
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