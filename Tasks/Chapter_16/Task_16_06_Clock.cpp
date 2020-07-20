#ifndef TASK_16_06_STDAFX_H
#include "Task_16_06_stdafx.h"
#include "Task_16_06_Clock.h"
#endif

Graph_lib::Clock::Clock(Point xy, int w, int h, const string& title)
	: Window{ xy, w, h, title }, 
	w{ w }, 
	h{ h }, 
	r{ w / 2 }, 
	clock{ Point(r, r), w * 0.3 }, 
	center{ Point(r, r), w * 0.015 }, 
	seconds{ Point(w / 2, h / 2),
		Point(w / 2 + static_cast<int>(sin(get_seconds() * 6 * pi / 180) * w / 4),
			h / 2 - static_cast<int>(cos(get_seconds() * 6 * pi / 180) * w / 4)) },
	minutes{ Point(w / 2, h / 2),
		Point(w / 2 + static_cast<int>(sin(get_minutes() * 6 * pi / 180) * w / 5),
			h / 2 - static_cast<int>(cos(get_minutes() * 6 * pi / 180) * w / 5)) }, 
	hours{ Point(w / 2, h / 2),
		Point(w / 2 + static_cast<int>(sin(get_hours() * 30 * pi / 180) * w / 6),
			h / 2 - static_cast<int>(cos(get_hours() * 30 * pi / 180) * w / 6)) }
{
	Point pcenter(w / 2, h / 2);
	clock.set_style(Line_style(Line_style::Line_style_type::solid, 4));
	clock.set_fill_color(Color::white);
	attach(clock);

	center.set_fill_color(Color::black);
	attach(center);

	seconds.set_style(Line_style(Line_style::dot, 4));
	seconds.set_color(Color::red);
	attach(seconds);

	minutes.set_style(Line_style(Line_style::dash, 6));
	minutes.set_color(Color::blue);
	attach(minutes);
	hours.set_style(Line_style(Line_style::solid , 8));
	hours.set_color(Color::green);
	attach(hours);
}

void Graph_lib::Clock::run_clock()
{
	std::cout << get_hours() << ' ' << get_minutes() << ' ' << get_seconds() << '\n';
	seconds.set_point(1, Point(w / 2 + static_cast<int>(sin(get_seconds() * 6 * pi / 180) * w / 4),
		h / 2 - static_cast<int>(cos(get_seconds() * 6 * pi / 180) * w / 4)));
	minutes.set_point(1, Point(w / 2 + static_cast<int>(sin(get_minutes() * 6 * pi / 180) * w / 5),
		h / 2 - static_cast<int>(cos(get_minutes() * 6 * pi / 180) * w / 5)));
	hours.set_point(1, Point(w / 2 + static_cast<int>(sin(get_hours() * 30 * pi / 180) * w / 6),
		h / 2 - static_cast<int>(cos(get_hours() * 30 * pi / 180) * w / 6)));
	redraw();
}

void Graph_lib::Clock::cb_run_clock(void* clock)
{
	Clock* c = (Clock*)clock;
	c->run_clock();
	Fl::repeat_timeout(1.0, Clock::cb_run_clock, clock);
}

int Graph_lib::Clock::get_seconds()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int seconds = newtime.tm_sec;
	return seconds;
}

int Graph_lib::Clock::get_minutes()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int minutes = newtime.tm_min;
	return minutes;
}

int Graph_lib::Clock::get_hours()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int hours = newtime.tm_hour;
	return hours;
}

Graph_lib::MyLine::MyLine(Point p1, Point p2)
{
	add(p1);
	add(p2);
}

void Graph_lib::MyLine::set_point(int i, Point p)
{
	Shape::set_point(i, p);
}
