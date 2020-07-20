#ifndef TASK_16_05_MYMENUMOVE_H
#define TASK_16_05_MYMENUMOVE_H

#ifndef TASK_16_05_STDAFX_H
#include "Task_16_05_stdafx.h"
#endif

namespace Graph_lib
{
	class My_window : public Window
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
	protected:
		int x;
		int y;
		Vector_ref<Shape> figures;
		void get_position();
	private:
		Button clear_btn;

		Menu mymenu;

		In_box x_pos;
		In_box y_pos;

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

	class MyMenuMove : public MyMenu
	{
	public:
		MyMenuMove(Point xy, int w, int h, const string& title);
	private:
		Button next_btn;

		void next();

		static void cb_move(Address, Address);
	};
}

#endif