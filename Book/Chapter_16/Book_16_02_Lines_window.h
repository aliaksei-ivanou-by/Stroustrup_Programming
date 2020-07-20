#ifndef BOOK_16_02_LINES_WINDOW_H
#define BOOK_16_02_LINES_WINDOW_H

#ifndef BOOK_16_02_STDAFX_H
#include "Book_16_02_stdafx.h"
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
		Button menu_button;

		void change(Color c);

		void hide_menu();

		void red_pressed();
		void blue_pressed();
		void black_pressed();
		void menu_pressed();
		void next();
		void quit();

		static void cb_red(Address, Address);
		static void cb_blue(Address, Address);
		static void cb_black(Address, Address);
		static void cb_menu(Address, Address);
		static void cb_next(Address, Address);
		static void cb_quit(Address, Address);
	};
}

#endif