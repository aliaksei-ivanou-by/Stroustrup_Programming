#ifndef TASK_16_03_IMAGE_BUTTON_H
#define TASK_16_03_IMAGE_BUTTON_H

#ifndef TASK_16_03_STDAFX_H
#include "Task_16_03_stdafx.h"
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

	class Image_Button : public My_window
	{
	public:
		Image_Button(Point xy, int w, int h, const string& title);
	private:
		Button image_btn;
		Image image;

		static void cb_move(Address, Address);;
		void move();
	};
}

#endif