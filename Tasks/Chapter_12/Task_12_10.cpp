#include "Simple_window.h"
#include "Graph.h"

int main()
try
{
	Point point(100, 100);
	Simple_window win(point, x_max() - 200, y_max() - 200, "My window");

	int cell_h = 8 * 5;
	int cell_w = 42 * 4;

	Line_style my_style(Line_style(Line_style::solid, 2));

	Graph_lib::Open_polyline line2_1;
	Point p2_1_1(200 + cell_w / 2, 250);
	Point p2_1_2(200 + cell_w / 2, 150 + cell_h);
	line2_1.add(p2_1_1);
	line2_1.add(p2_1_2);
	line2_1.set_style(my_style);
	line2_1.set_color(Color::red);
	win.attach(line2_1);

	Graph_lib::Open_polyline line2_10;
	Point p2_10_1(200 + cell_w / 2, 250);
	Point p2_10_2(510 + cell_w / 2, 110 + cell_h);
	line2_10.add(p2_10_1);
	line2_10.add(p2_10_2);
	line2_10.set_style(my_style);
	line2_10.set_color(Color::red);
	win.attach(line2_10);

	Graph_lib::Open_polyline line7_1;
	Point p7_1_1(500 + cell_w / 2, 200);
	Point p7_1_2(200 + cell_w / 2, 150 + cell_h);
	line7_1.add(p7_1_1);
	line7_1.add(p7_1_2);
	line7_1.set_style(my_style);
	line7_1.set_color(Color::red);
	win.attach(line7_1);

	Graph_lib::Open_polyline line3_2;
	Point p3_2_1(100 + cell_w / 2, 350);
	Point p3_2_2(200 + cell_w / 2, 250 + cell_h);
	line3_2.add(p3_2_1);
	line3_2.add(p3_2_2);
	line3_2.set_style(my_style);
	line3_2.set_color(Color::red);
	win.attach(line3_2);

	Graph_lib::Open_polyline line4_2;
	Point p4_2_1(210 + cell_w / 2, 450);
	Point p4_2_2(200 + cell_w / 2, 250 + cell_h);
	line4_2.add(p4_2_1);
	line4_2.add(p4_2_2);
	line4_2.set_style(my_style);
	line4_2.set_color(Color::red);
	win.attach(line4_2);

	Graph_lib::Open_polyline line4_6;
	Point p4_6_1(210 + cell_w / 2, 450);
	Point p4_6_2(420 + cell_w / 2, 380 + cell_h);
	line4_6.add(p4_6_1);
	line4_6.add(p4_6_2);
	line4_6.set_style(my_style);
	line4_6.set_color(Color::red);
	win.attach(line4_6);

	Graph_lib::Open_polyline line5_7;
	Point p5_7_1(400 + cell_w / 2, 300);
	Point p5_7_2(500 + cell_w / 2, 200 + cell_h);
	line5_7.add(p5_7_1);
	line5_7.add(p5_7_2);
	line5_7.set_style(my_style);
	line5_7.set_color(Color::red);
	win.attach(line5_7);

	Graph_lib::Open_polyline line6_7;
	Point p6_7_1(420 + cell_w / 2, 380);
	Point p6_7_2(500 + cell_w / 2, 200 + cell_h);
	line6_7.add(p6_7_1);
	line6_7.add(p6_7_2);
	line6_7.set_style(my_style);
	line6_7.set_color(Color::red);
	win.attach(line6_7);

	Graph_lib::Open_polyline line9_8;
	Point p9_8_1(600 + cell_w / 2, 380);
	Point p9_8_2(600 + cell_w / 2, 300 + cell_h);
	line9_8.add(p9_8_1);
	line9_8.add(p9_8_2);
	line9_8.set_style(my_style);
	line9_8.set_color(Color::red);
	win.attach(line9_8);

	Graph_lib::Open_polyline line6_8;
	Point p6_8_1(420 + cell_w / 2, 380);
	Point p6_8_2(600 + cell_w / 2, 300 + cell_h);
	line6_8.add(p6_8_1);
	line6_8.add(p6_8_2);
	line6_8.set_style(my_style);
	line6_8.set_color(Color::red);
	win.attach(line6_8);

	Graph_lib::Open_polyline line8_7;
	Point p8_7_1(600 + cell_w / 2, 300);
	Point p8_7_2(500 + cell_w / 2, 200 + cell_h);
	line8_7.add(p8_7_1);
	line8_7.add(p8_7_2);
	line8_7.set_style(my_style);
	line8_7.set_color(Color::red);
	win.attach(line8_7);

	Graph_lib::Open_polyline line8_10;
	Point p8_10_1(600 + cell_w / 2, 300);
	Point p8_10_2(510 + cell_w / 2, 110 + cell_h);
	line8_10.add(p8_10_1);
	line8_10.add(p8_10_2);
	line8_10.set_style(my_style);
	line8_10.set_color(Color::red);
	win.attach(line8_10);

	Graph_lib::Open_polyline line11_10;
	Point p11_10_1(700 + cell_w / 2, 150);
	Point p11_10_2(510 + cell_w / 2, 110 + cell_h);
	line11_10.add(p11_10_1);
	line11_10.add(p11_10_2);
	line11_10.set_style(my_style);
	line11_10.set_color(Color::red);
	win.attach(line11_10);

	Graph_lib::Open_polyline line7_10;
	Point p7_10_1(500 + cell_w / 2, 200);
	Point p7_10_2(510 + cell_w / 2, 110 + cell_h);
	line7_10.add(p7_10_1);
	line7_10.add(p7_10_2);
	line7_10.set_style(my_style);
	line7_10.set_color(Color::red);
	win.attach(line7_10);

	Graph_lib::Rectangle box1(Point(200, 150), cell_w, cell_h);
	box1.set_fill_color(Color::white);
	box1.set_color(Color::black);
	Text t1_1{ Point{200, 145}, "Point.h:" };
	t1_1.set_font(Font::helvetica_bold);
	t1_1.set_font_size(11);
	t1_1.set_color(Color::black);
	Text t1_2{ Point{210, 165}, "struct Point { ... };" };
	t1_2.set_font(Font::helvetica_bold);
	t1_2.set_font_size(10);
	t1_2.set_color(Color::black);
	win.attach(box1);
	win.attach(t1_1);
	win.attach(t1_2);

	Graph_lib::Rectangle box2(Point(200, 250), cell_w, cell_h);
	box2.set_fill_color(Color::white);
	box2.set_color(Color::black);
	Text t2_1{ Point{200, 245}, "Graph.h:" };
	t2_1.set_font(Font::helvetica_bold);
	t2_1.set_font_size(11);
	t2_1.set_color(Color::black);
	Text t2_21{ Point{210, 265}, "// Graphical interface" };
	t2_21.set_font(Font::helvetica_bold);
	t2_21.set_font_size(10);
	t2_21.set_color(Color::black);
	Text t2_22{ Point{210, 275}, "struct Shape { ... };" };
	t2_22.set_font(Font::helvetica_bold);
	t2_22.set_font_size(10);
	t2_22.set_color(Color::black);
	win.attach(box2);
	win.attach(t2_1);
	win.attach(t2_21);
	win.attach(t2_22);

	Graph_lib::Rectangle box3(Point(100, 350), cell_w, cell_h);
	win.attach(box3);
	box3.set_fill_color(Color::white);
	box3.set_color(Color::black);
	Text t3_1{ Point{100, 345}, "Graph.cpp:" };
	t3_1.set_font(Font::helvetica_bold);
	t3_1.set_font_size(11);
	t3_1.set_color(Color::black);
	Text t3_2{ Point{110, 365}, "Graphic code" };
	t3_2.set_font(Font::helvetica_bold);
	t3_2.set_font_size(10);
	t3_2.set_color(Color::black);
	win.attach(box3);
	win.attach(t3_1);
	win.attach(t3_2);

	Graph_lib::Rectangle box4(Point(210, 450), cell_w, cell_h);
	win.attach(box4);
	box4.set_fill_color(Color::white);
	box4.set_color(Color::black);
	Text t4_1{ Point{210, 445}, "chapter12.cpp:" };
	t4_1.set_font(Font::helvetica_bold);
	t4_1.set_font_size(11);
	t4_1.set_color(Color::black);
	Text t4_21{ Point{220, 465}, "#include \"Graph.h\"" };
	t4_21.set_font(Font::helvetica_bold);
	t4_21.set_font_size(10);
	t4_21.set_color(Color::black);
	Text t4_22{ Point{220, 475}, "#include \"Simple_window.h\"" };
	t4_22.set_font(Font::helvetica_bold);
	t4_22.set_font_size(10);
	t4_22.set_color(Color::black);
	Text t4_23{ Point{220, 485}, "int main() { ... }" };
	t4_23.set_font(Font::helvetica_bold);
	t4_23.set_font_size(10);
	t4_23.set_color(Color::black);
	win.attach(box4);
	win.attach(t4_1);
	win.attach(t4_21);
	win.attach(t4_22);
	win.attach(t4_23);

	Graph_lib::Rectangle box5(Point(400, 300), cell_w, cell_h);
	win.attach(box5);
	box5.set_fill_color(Color::white);
	box5.set_color(Color::black);
	Text t5_1{ Point{400, 295}, "Window.cpp:" };
	t5_1.set_font(Font::helvetica_bold);
	t5_1.set_font_size(11);
	t5_1.set_color(Color::black);
	Text t5_2{ Point{410, 315}, "Window code" };
	t5_2.set_font(Font::helvetica_bold);
	t5_2.set_font_size(10);
	t5_2.set_color(Color::black);
	win.attach(box5);
	win.attach(t5_1);
	win.attach(t5_2);

	Graph_lib::Rectangle box6(Point(420, 380), cell_w, cell_h);
	win.attach(box6);
	box6.set_fill_color(Color::white);
	box6.set_color(Color::black);
	Text t6_1{ Point{420, 375}, "Simple_window.cpp:" };
	t6_1.set_font(Font::helvetica);
	t6_1.set_font_size(11);
	t6_1.set_color(Color::black);
	Text t6_21{ Point{430, 395}, "// Window interface" };
	t6_21.set_font(Font::helvetica_bold);
	t6_21.set_font_size(10);
	t6_21.set_color(Color::black);
	t6_21.set_color(Color::black);
	Text t6_22{ Point{430, 405}, "class Simple_window { ... };" };
	t6_22.set_font(Font::helvetica_bold);
	t6_22.set_font_size(10);
	t6_22.set_color(Color::black);
	Text t6_23{ Point{430, 415}, "..." };
	t6_23.set_font(Font::helvetica_bold);
	t6_23.set_font_size(10);
	t6_23.set_color(Color::black);
	win.attach(box6);
	win.attach(t6_1);
	win.attach(t6_21);
	win.attach(t6_22);
	win.attach(t6_23);

	Graph_lib::Rectangle box7(Point(500, 200), cell_w, cell_h);
	win.attach(box7);
	box7.set_fill_color(Color::white);
	box7.set_color(Color::black);
	Text t7_1{ Point{500, 195}, "Window.h:" };
	t7_1.set_font(Font::helvetica_bold);
	t7_1.set_font_size(11);
	t7_1.set_color(Color::black);
	Text t7_21{ Point{510, 215}, "// Window interface" };
	t7_21.set_font(Font::helvetica_bold);
	t7_21.set_font_size(10);
	t7_21.set_color(Color::black);
	t7_1.set_color(Color::black);
	Text t7_22{ Point{510, 225}, "class Window { ... };" };
	t7_22.set_font(Font::helvetica_bold);
	t7_22.set_font_size(10);
	t7_22.set_color(Color::black);
	Text t7_23{ Point{510, 235}, "..." };
	t7_23.set_font(Font::helvetica_bold);
	t7_23.set_font_size(10);
	t7_23.set_color(Color::black);
	win.attach(box7);
	win.attach(t7_1);
	win.attach(t7_21);
	win.attach(t7_22);
	win.attach(t7_23);

	Graph_lib::Rectangle box8(Point(600, 300), cell_w, cell_h);
	win.attach(box8);
	box8.set_fill_color(Color::white);
	box8.set_color(Color::black);
	Text t8_1{ Point{600, 295}, "GUI.h:" };
	t8_1.set_font(Font::helvetica);
	t8_1.set_font_size(11);
	t8_1.set_color(Color::black);
	Text t8_21{ Point{610, 315}, "// Interface GUI" };
	t8_21.set_font(Font::helvetica_bold);
	t8_21.set_font_size(10);
	t8_21.set_color(Color::black);
	t8_21.set_color(Color::black);
	Text t8_22{ Point{610, 325}, "struct In_box { ... };" };
	t8_22.set_font(Font::helvetica_bold);
	t8_22.set_font_size(10);
	t8_22.set_color(Color::black);
	Text t8_23{ Point{610, 335}, "..." };
	t8_23.set_font(Font::helvetica_bold);
	t8_23.set_font_size(10);
	t8_23.set_color(Color::black);
	win.attach(box8);
	win.attach(t8_1);
	win.attach(t8_21);
	win.attach(t8_22);
	win.attach(t8_23);

	Graph_lib::Rectangle box9(Point(600, 380), cell_w, cell_h);
	win.attach(box9);
	box9.set_fill_color(Color::white);
	box9.set_color(Color::black);
	Text t9_1{ Point{600, 375}, "GUI.cpp:" };
	t9_1.set_font(Font::helvetica_bold);
	t9_1.set_font_size(11);
	t9_1.set_color(Color::black);
	Text t9_2{ Point{610, 395}, "Code GUI" };
	t9_2.set_font(Font::helvetica_bold);
	t9_2.set_font_size(10);
	t9_2.set_color(Color::black);
	win.attach(box9);
	win.attach(t9_1);
	win.attach(t9_2);

	Graph_lib::Rectangle box10_1(Point(500, 100), cell_w, cell_h);
	box10_1.set_fill_color(Color::white);
	box10_1.set_color(Color::black);
	win.attach(box10_1);

	Graph_lib::Rectangle box10_2(Point(505, 105), cell_w, cell_h);
	box10_2.set_fill_color(Color::white);
	box10_2.set_color(Color::black);
	win.attach(box10_2);

	Graph_lib::Rectangle box10_3(Point(510, 110), cell_w, cell_h);
	box10_3.set_fill_color(Color::white);
	box10_3.set_color(Color::black);
	Text t10_3_2{ Point{515, 125}, "Header files FLTK" };
	t10_3_2.set_font(Font::helvetica_bold);
	t10_3_2.set_font_size(10);
	t10_3_2.set_color(Color::black);
	win.attach(box10_3);
	win.attach(t10_3_2);

	Graph_lib::Rectangle box11_1(Point(700, 150), cell_w, cell_h);
	box11_1.set_fill_color(Color::white);
	box11_1.set_color(Color::black);
	win.attach(box11_1);

	Graph_lib::Rectangle box11_2(Point(705, 155), cell_w, cell_h);
	box11_2.set_fill_color(Color::white);
	box11_2.set_color(Color::black);
	win.attach(box11_2);

	Graph_lib::Rectangle box11_3(Point(710, 160), cell_w, cell_h);
	box11_3.set_fill_color(Color::white);
	box11_3.set_color(Color::black);
	Text t11_3_2{ Point{715, 175}, "Code FLTK" };
	t11_3_2.set_font(Font::helvetica_bold);
	t11_3_2.set_font_size(10);
	t11_3_2.set_color(Color::black);
	win.attach(box11_3);
	win.attach(t11_3_2);

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