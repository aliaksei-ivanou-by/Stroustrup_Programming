#ifndef TASK_16_00_01_LINES_WINDOW_H
#define TASK_16_00_01_LINES_WINDOW_H

#ifndef TASK_16_00_01_STDAFX_H
#include "Task_16_00_01_stdafx.h"
#endif

namespace Graph_lib
{
	class Lines_window : Window
	{
	public:
		Lines_window(Point xy, int w, int h, const std::string& title);
	private:
		Open_polyline lines;

		Button next_button;
		Button quit_button;
		In_box next_x;
		In_box next_y;
		Out_box xy_out;
		Menu color_menu;
		Button cmenu_button;
		Menu style_menu;
		Button smenu_button;

		void change(Color c);
		void change_style(Line_style ls);

		void hide_cmenu();
		void hide_smenu();

		void red_pressed();
		void blue_pressed();
		void black_pressed();
		void cmenu_pressed();
		void solid_pressed();
		void dot_pressed();
		void dash_pressed();
		void smenu_pressed();
		void next();
		void quit();

		static void cb_red(Address, Address);
		static void cb_blue(Address, Address);
		static void cb_black(Address, Address);
		static void cb_cmenu(Address, Address);
		static void cb_solid(Address, Address);
		static void cb_dot(Address, Address);
		static void cb_dash(Address, Address);
		static void cb_smenu(Address, Address);
		static void cb_next(Address, Address);
		static void cb_quit(Address, Address);
	};
}

#endif