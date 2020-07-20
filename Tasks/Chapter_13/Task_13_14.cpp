#include "Task_13_14_Right_triangle.h"

int main()
try
{
	srand(time(NULL));
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Point p(200, 250);
	int side1 = 100;
	int side2 = 100;
	double angle = 0;
	Vector_ref <Right_triangle> figure;

	for (int i = 0; i < 8; ++i)
	{
		figure.push_back(new Right_triangle(p, side1, side2, angle));
		figure[figure.size() - 1].set_fill_color(Color(rand() % 16));
		win.attach(figure[figure.size() - 1]);

		p.x -= cos((90 - angle) * pi / 180) * side2;
		p.y -= sin((90 - angle) * pi / 180) * side2;

		angle -= 45;
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