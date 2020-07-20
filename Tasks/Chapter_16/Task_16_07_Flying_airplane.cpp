#ifndef TASK_16_07_STDAFX_H
#include "Task_16_07_stdafx.h"
#include "Task_16_07_Flying_airplane.h"
#endif

Graph_lib::Flying_airplane::Flying_airplane(Point xy, int w, int h, const string& title)
	: Window{ xy, w, h, title },
	start_btn{ Point(0, 0), 100, 20, "Start", cb_start_btn },
	stop_btn{ Point(0, 20), 100, 20, "Stop", cb_stop_btn },
	image{ Point(0, 60), "airplane.jpg" },
	xy{ xy },
	w{ w },
	h{ h }
{
	attach(start_btn);
	attach(stop_btn);
	attach(image);
}

void Graph_lib::Flying_airplane::fly()
{
	if (is_flying)
	{
		image.move(dx, dy);
		ddx++;
		ddy++;
		redraw();
		if ((image.point(0).x > w) || (image.point(0).y > h))
		{
			is_flying == false;
			image.move(-ddx, -ddy);
			ddx = 0;
			ddy = 0;
			redraw();
			is_flying == true;
		}
	}
}

void Graph_lib::Flying_airplane::cb_fly(void* f)
{
	Flying_airplane* airplane = (Flying_airplane*) f;
	airplane->fly();
	Fl::repeat_timeout(0.1, cb_fly, airplane);
}

void Graph_lib::Flying_airplane::cb_start_btn(Address, Address pw)
{
	reference_to<Flying_airplane>(pw).is_flying = true;
}

void Graph_lib::Flying_airplane::cb_stop_btn(Address, Address pw)
{
	reference_to<Flying_airplane>(pw).is_flying = false;
}
