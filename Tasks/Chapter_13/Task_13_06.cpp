#include "Task_13_06_Box_text.h"
#include "Task_13_03_Arrow.h"
#include "Task_13_04_ConPoints.h"

int main()
try
{
	// boxes
	Simple_window win(Point(100, 100), x_max() - 200, y_max() - 200, "Simple_window");
	Box_text box1(Point(50, 50), "Window");
	box1.set_color(Color::black);
	win.attach(box1);
	Box_text box2(Point(50, 160), "Simple_window");
	box2.set_color(Color::black);
	win.attach(box2);
	Box_text box3(Point(250, 50), "Line_style");
	box3.set_color(Color::black);
	win.attach(box3);
	Box_text box4(Point(450, 50), "Color");
	box4.set_color(Color::black);
	win.attach(box4);
	Box_text box5(Point(500, 160), "Point");
	box5.set_color(Color::black);
	win.attach(box5);
	Box_text box6(Point(250, 160), "Shape");
	box6.set_color(Color::black);
	win.attach(box6);
	Box_text box7(Point(50, 320), "Line");
	box7.set_color(Color::black);
	win.attach(box7);
	Box_text box8(Point(150, 320), "Lines");
	box8.set_color(Color::black);
	win.attach(box8);
	Box_text box9(Point(250, 320), "Polygon");
	box9.set_color(Color::black);
	win.attach(box9);
	Box_text box10(Point(350, 320), "Axis");
	box10.set_color(Color::black);
	win.attach(box10);
	Box_text box11(Point(450, 320), "Rectangle");
	box11.set_color(Color::black);
	win.attach(box11);
	Box_text box12(Point(550, 320), "Text");
	box12.set_color(Color::black);
	win.attach(box12);
	Box_text box13(Point(650, 320), "Image");
	box13.set_color(Color::black);
	win.attach(box13);
	// lines
	Arrow line1(n(box7), sw(box6));
	win.attach(line1);
	Arrow line2(n(box8), sw(box6));
	win.attach(line2);
	Arrow line3(n(box9), s(box6));
	win.attach(line3);
	Arrow line4(n(box10), s(box6));
	win.attach(line4);
	Arrow line5(n(box11), s(box6));
	win.attach(line5);
	Arrow line6(n(box12), se(box6));
	win.attach(line6);
	Arrow line7(n(box13), se(box6));
	win.attach(line7);
	Arrow line8(n(box2), s(box1));
	win.attach(line8);
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