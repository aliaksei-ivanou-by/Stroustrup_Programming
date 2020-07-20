#ifndef BOOK_15_02_STDAFX_H
#include "Book_15_02_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Axis x(Axis::x, Point(20, y_orig), xlength, xlength / x_scale, "one notch == 1");
	Axis y(Axis::y, Point(x_orig, ylength + 20), ylength, ylength / y_scale, "one notch == 1");
	win.attach(x);
	win.attach(y);
	x.set_color(Color::red);
	y.set_color(Color::red);

	Function real_exp(exp, r_min, r_max, orig, 200, x_scale, y_scale);
	real_exp.set_color(Color::blue);
	win.attach(real_exp);
	win.wait_for_button();

	for (int n = 0; n < 50; ++n)
	{
		ostringstream ss;
		ss << "exp aproximation; n == " << n;
		win.set_label(ss.str());
		expN_number_of_terms = n;
		Function e(expN, r_min, r_max, orig, 200, x_scale, y_scale);
		win.attach(e);
		win.wait_for_button();
		win.detach(e);
	}
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