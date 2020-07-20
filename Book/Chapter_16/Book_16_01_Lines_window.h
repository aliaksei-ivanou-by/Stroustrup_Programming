#ifndef BOOK_16_01_LINES_WINDOW_H
#define BOOK_16_01_LINES_WINDOW_H

#ifndef BOOK_16_01_STDAFX_H
#include "Book_16_01_stdafx.h"
#endif

namespace Graph_lib
{
	class Lines_window : Window
	{
	public:
		Lines_window(Point xy, int w, int h, const std::string& title);
		Open_polyline lines;
	private:
		Button next_button;
		Button quit_button;
		In_box next_x;
		In_box next_y;
		Out_box xy_out;
		void next();
		void quit();
	};
}

#endif