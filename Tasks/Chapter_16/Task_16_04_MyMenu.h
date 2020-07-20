#ifndef TASK_16_04_MYMENU_H
#define TASK_16_04_MYMENU_H

#ifndef TASK_16_04_STDAFX_H
#include "Task_16_04_stdafx.h"
#endif

namespace Graph_lib
{
	class My_window : public Simple_window
	{
	public:
		My_window(Point xy, int w, int h, const string& title);
	private:
		Button quit_button;
		static void cb_quit(Address, Address);
		void quit();
	};

	class MyMenu : public My_window
	{
	public:
		MyMenu(Point xy, int w, int h, const string& title);
	private:
		int x;
		int y;

		Button clear_btn;

		Menu mymenu;

		In_box x_pos;
		In_box y_pos;

		Vector_ref<Shape> figures;

		void get_position();

		void draw_circle();
		void draw_square();
		void draw_triangle();
		void draw_hexagon();

		static void cb_circle(Address, Address);
		static void cb_square(Address, Address);
		static void cb_triangle(Address, Address);
		static void cb_hexagon(Address, Address);
		static void cb_clear(Address, Address);

		void clear();
	};
}

#endif