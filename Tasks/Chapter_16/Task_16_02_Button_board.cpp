#ifndef TASK_16_02_STDAFX_H
#include "Task_16_02_stdafx.h"
#include "Task_16_02_Button_board.h"
#endif

My_window::My_window(Point xy, int w, int h, const string& title)
	: Simple_window{ xy, w, h, title },
	quit_button{ Point(x_max() - 70, 30), 70, 20, "Quit", cb_quit }
{
	attach(quit_button);
}

void My_window::cb_quit(Address, Address pw)
{
	reference_to<My_window>(pw).quit();
}

void My_window::quit()
{
	hide();
}

Button_board::Button_board(Point xy, int w, int h, const string& title, int t_r, int t_c)
	: My_window{ xy, w, h, title },
	table_row{ t_r },
	table_column{ t_c },
	xy_out{ Point(x_max() - 70, 60), 70, 20, "(x, y)" }
{
	buttons.resize(table_row);
	for (int i = 0; i < table_row; ++i)
	{
		buttons[i].resize(table_column);
	}
	for (i = 0; i < table_column; ++i)
	{
		Menu* m = new Menu(Point(i * 50, 0), 50, 50, Menu::vertical, "menu");
		for (j = 0; j < table_row; ++j)
		{
			Button* b = new Button(Point(0, 0), 0, 0, std::to_string(j + 1) + "-" + std::to_string(i + 1),
				[](Address b, Address pw)
				{
					string str = reference_to<Button_board>(b).select_button();
					reference_to<Button_board>(pw).select_label(str);
				}
			);
			buttons[j].push_back(b);
			m->attach(*b);
		}
		attach(*m);
	}
	attach(xy_out);
	xy_out.put("no point");
}

std::string Graph_lib::Button_board::select_button()
{
	std::cout << "button address = " << this << '\n';
	string str = '(' + std::to_string((*this).x()) + ',' + std::to_string((*this).y()) + ')';
	return str;
}

void Graph_lib::Button_board::select_label(string str)
{
	std::cout << "label address = " << this << '\n';
	xy_out.put(str);
}

