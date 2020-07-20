#ifndef TASK_16_03_STDAFX_H
#include "Task_16_03_stdafx.h"
#include "Task_16_03_Image_Button.h"
#endif

Graph_lib::My_window::My_window(Point xy, int w, int h, const string& title)
	: Simple_window{ xy, w, h, title },
	quit_button{ Point(x_max() - 70, 30), 70, 20, "Quit", cb_quit }
{
	attach(quit_button);
}

void Graph_lib::My_window::cb_quit(Address, Address pw)
{
	reference_to<My_window>(pw).quit();
}

void Graph_lib::My_window::quit()
{
	hide();
}

Graph_lib::Image_Button::Image_Button(Point xy, int w, int h, const string& title)
	: My_window{ xy, w, h, title }, 
	image_btn{ Point(randint(0, x_max() - 100), randint(0, y_max() - 100)), 100, 100, "", cb_move }, 
	image{ image_btn.loc, "snow_cpp.gif" }
{
	attach(image_btn);
	image.set_mask(Point(100, 100), 100, 100);
	attach(image);
}

void Graph_lib::Image_Button::cb_move(Address, Address pw)
{
	reference_to<Image_Button>(pw).move();
}

void Graph_lib::Image_Button::move()
{
	int dx = randint(0, x_max() - 100) - image_btn.loc.x;
	int dy = randint(0, y_max() - 100) - image_btn.loc.y;
	image.move(dx, dy);
	image_btn.move(dx, dy);
}
