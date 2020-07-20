#ifndef BOOK_15_03_STDAFX_H
#include "Book_15_03_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), xmax, ymax, "Aging Japan");
	
	string file_name = "japanese-age-data.txt";
	ifstream ifs(file_name.c_str());
	if (!ifs)
	{
		error("Unable to open file ", file_name);
	}

	Scale xs(xoffset, base_year, xscale);
	Scale ys(ymax - yoffset, 0, -yscale);

	Axis x(Axis::x, 
		Point(xoffset, ymax - yoffset), 
		xlength,
		(end_year - base_year) / 10,
		"year   1960      1970      1980      1990      "
		"2000      2010      2020      2030      2040");
	x.label.move(-200, 0);
	Axis y(Axis::y, 
		Point(xoffset, ymax - yoffset), 
		ylength, 
		10, 
		"% of population");
	Line current_year(Point(xs(2020), ys(0)), Point(xs(2020), ys(100)));
	current_year.set_style(Line_style::dash);

	Open_polyline children;
	Open_polyline adults;
	Open_polyline aged;

	Distribution d;
	while (ifs >> d)
	{
		if (d.year < base_year || end_year < d.year)
		{
			error("Year out of range");
		}
		if (d.young + d.middle + d.old != 100)
		{
			error("Percentages don't add up");
		}
		int x = xs(d.year);
		children.add(Point(x, ys(d.young)));
		adults.add(Point(x, ys(d.middle)));
		aged.add(Point(x, ys(d.old)));
	}

	Text children_label(Point(20, children.point(0).y), "age 0-14");
	children.set_color(Color::red);
	children_label.set_color(Color::red);

	Text adults_label(Point(20, adults.point(0).y), "age 15-64");
	adults.set_color(Color::blue);
	adults_label.set_color(Color::blue);

	Text aged_label(Point(20, aged.point(0).y), "age 65+");
	aged.set_color(Color::dark_green);
	aged_label.set_color(Color::dark_green);

	win.attach(children);
	win.attach(adults);
	win.attach(aged);

	win.attach(children_label);
	win.attach(adults_label);
	win.attach(aged_label);

	win.attach(x);
	win.attach(y);
	win.attach(current_year);

	gui_main();
	return 0;
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