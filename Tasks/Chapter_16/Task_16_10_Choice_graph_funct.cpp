#ifndef TASK_16_10_STDAFX_H
#include "Task_16_10_stdafx.h"
#include "Task_16_10_Choice_graph_funct.h"
#endif

double one(double)
{
	return 1;
}

double slope(double x)
{
	return x / 2;
}

double square(double x)
{
	return x * x;
}

double sloping_cos(double x)
{
	return cos(x) + slope(x);
}

double get_double(In_box& input)
{
	string str;
	str = input.get_string();
	if (str == "")
	{
		error("No input");
	}
	istringstream iss(str);
	double output;
	iss >> output;
	if (!iss)
	{
		error("Bad input");
	}
	return output;
}

int get_int(In_box& input)
{
	int output = input.get_int();
	return output;
}

Graph_lib::Choice_graph_funct::Choice_graph_funct(Point xy, int w, int h, const string& title)
	: Window{ xy, w, h, title },
	x_axis{ Axis::x, Point(x_orig - xlength / 2 - 7, y_orig), xlength, xlength / x_scale, "" },
	y_axis{ Axis::y, Point(x_orig, y_orig + ylength / 2), ylength, ylength / y_scale, "" },
	func{ sin, r_min, r_max, orig, n_points, x_scale, y_scale },
	func_ptr{ sin },
	r1_in{ Point(x_max() - 75, 20), 75, 20, "r min: " },
	r2_in{ Point(x_max() - 75, 40), 75, 20, "r max: " },
	n_points_in{ Point(x_max() - 75, 60), 75, 20, "n points: " },
	x_scale_in{ Point(x_max() - 75, 80), 75, 20, "x scale: " },
	y_scale_in{ Point(x_max() - 75, 100), 75, 20, "y scale: " },
	draw_btn{ Point(x_max() - 150, 0), 150, 20, "Draw function", cb_draw_btn },
	menu_func{ Point(x_max() - 150, 120), 150, 20, Menu::vertical, "Functions" }
{
	get_functions();

	attach(draw_btn);
	for (int i = 0; i < v_func.size(); ++i)
	{
		Button* b = new Button(Point(0, 0), 0, 0, v_func[i].second, 
			[](Address b, Address pw)
			{
				int key = reference_to<Choice_graph_funct>(b).get_n_func();
				reference_to<Choice_graph_funct>(pw).func_pressed(key);
			}
		);
		menu_func.attach(*b);
	}
	attach(menu_func);

	attach(r1_in);
	attach(r2_in);
	attach(n_points_in);
	attach(x_scale_in);
	attach(y_scale_in);

	attach(x_axis);
	attach(y_axis);

	func.set_color(Color::invisible);
	attach(func);
}

void Graph_lib::Choice_graph_funct::get_functions()
{
	v_func.push_back(pair<double (*)(double), string>(sin, "Sin"));
	v_func.push_back(pair<double (*)(double), string>(cos, "Cos"));
	v_func.push_back(pair<double (*)(double), string>(exp, "Exp"));
	v_func.push_back(pair<double (*)(double), string>(log, "Log"));
	v_func.push_back(pair<double (*)(double), string>(one, "One"));
	v_func.push_back(pair<double (*)(double), string>(slope, "Slope"));
	v_func.push_back(pair<double (*)(double), string>(square, "Square"));
	v_func.push_back(pair<double (*)(double), string>(sloping_cos, "Sloping Cos"));
}

void Graph_lib::Choice_graph_funct::draw_btn_pressed()
{
	func.set_range(get_double(r1_in), get_double(r2_in));
	func.set_n_points(get_int(n_points_in));
	func.set_x_scale(get_double(x_scale_in));
	func.set_y_scale(get_double(y_scale_in));
	func.set_func(func_ptr);
	func.set_color(Color::red);
	redraw();
}

int Graph_lib::Choice_graph_funct::get_n_func()
{
	int k = (*this).y() - 120;
	int key = 0;
	while (k != 0)
	{
		k -= 20;
		key++;
	}
	return key;
}

void Graph_lib::Choice_graph_funct::func_pressed(int key)
{
	func_ptr = v_func[key].first;
}

void Graph_lib::Choice_graph_funct::cb_draw_btn(Address, Address pw)
{
	reference_to<Choice_graph_funct>(pw).draw_btn_pressed();
}