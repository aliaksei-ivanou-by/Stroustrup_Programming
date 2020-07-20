#include "Task_13_04_ConPoints.h"
#include "main.h"

int main()
try
{
	Simple_window win(Point(100, 100), x_max() - 100, y_max() - 100, "Simple_window");
	Graph_lib::Rectangle rec(Point(150, 150), 150, 250);
	Graph_lib::Marks m1("1"), m2("2"), m3("3"), m4("4"), m5("5"), m6("6"), m7("7"), m8("8"), m9("9");
	m2.add(n(rec));
	m8.add(w(rec));
	m6.add(s(rec));
	m4.add(e(rec));
	m1.add(center(rec));
	m9.add(nw(rec));
	m3.add(ne(rec));
	m7.add(sw(rec));
	m5.add(se(rec));
	win.attach(rec);
	win.attach(m1);
	win.attach(m2);
	win.attach(m3);
	win.attach(m4);
	win.attach(m5);
	win.attach(m6);
	win.attach(m7);
	win.attach(m8);
	win.attach(m9);
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