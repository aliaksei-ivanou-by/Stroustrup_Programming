#include "Task_13_05_ConPoints.h"

int main()
try
{
	Simple_window win(Point(100, 100), x_max() - 100, y_max() - 100, "Simple_window");
	// Circle
	Graph_lib::Circle c(Point (150, 150), 100);
	Graph_lib::Marks mc1("1"), mc2("2"), mc3("3"), mc4("4"), mc5("5"), mc6("6"), mc7("7"), mc8("8"), mc9("9");
	mc2.add(n(c));
	mc8.add(w(c));
	mc6.add(s(c));
	mc4.add(e(c));
	mc1.add(center(c));
	mc9.add(nw(c));
	mc3.add(ne(c));
	mc7.add(sw(c));
	mc5.add(se(c));
	win.attach(c);
	win.attach(mc1);
	win.attach(mc2);
	win.attach(mc3);
	win.attach(mc4);
	win.attach(mc5);
	win.attach(mc6);
	win.attach(mc7);
	win.attach(mc8);
	win.attach(mc9);
	// Ellipse
	Graph_lib::Ellipse el(Point(400, 400), 50, 150);
	Graph_lib::Marks me1("1"), me2("2"), me3("3"), me4("4"), me5("5"), me6("6"), me7("7"), me8("8"), me9("9");
	me2.add(n(el));
	me8.add(w(el));
	me6.add(s(el));
	me4.add(e(el));
	me1.add(center(el));
	me9.add(nw(el));
	me3.add(ne(el));
	me7.add(sw(el));
	me5.add(se(el));
	win.attach(el);
	win.attach(me1);
	win.attach(me2);
	win.attach(me3);
	win.attach(me4);
	win.attach(me5);
	win.attach(me6);
	win.attach(me7);
	win.attach(me8);
	win.attach(me9);
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