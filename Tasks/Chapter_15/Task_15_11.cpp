#ifndef TASK_15_11_STDAFX_H
#include "Task_15_11_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), xmax, ymax, "Simple_window");

	string file_name = "mean_temperature.txt";
	ifstream ifs(file_name.c_str());
	if (!ifs)
	{
		error("Unable to open file ", file_name);
	}

	Scale xs(xoffset, base_month, xscale);
	Scale ys(ymax - yoffset, -10, -yscale);

	Axis x(Axis::x, Point(xoffset, ymax - yoffset), xlength, (end_month - base_month),
		"month         1               2               3               4                5               6               "
		"7               8               9               10             11             12");
	x.label.move(-330, 0);

	Axis y(Axis::y, Point(xoffset, ymax - yoffset), ylength, 20, "Average temperature");

	Line zero(Point(xs(1), ys(0)), Point(xs(end_month), ys(0)));
	zero.set_style(Line_style::dash);

	Open_polyline f1;
	Open_polyline f2;

	Temperature tm;
	while (ifs >> tm)
	{
		if (tm.month < base_month || tm.month > end_month)
		{
			error("Month out of range");
		}
		int x = xs(tm.month);
		f1.add(Point(x, ys(tm.t1)));
		f2.add(Point(x, ys(tm.t2)));
	}

	Text f1_label(Point(xmax - 300, 50), "Cambridge, England");
	f1.set_color(Color::red);
	f1_label.set_color(Color::red);

	Text f2_label(Point(xmax - 300, 70), "Cambridge, Massachusetts, USA");
	f2.set_color(Color::blue);
	f2_label.set_color(Color::blue);

	win.attach(f1);
	win.attach(f2);

	win.attach(f1_label);
	win.attach(f2_label);

	win.attach(x);
	win.attach(y);
	win.attach(zero);

	win.wait_for_button();
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}