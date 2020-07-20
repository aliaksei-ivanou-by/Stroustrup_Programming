#ifndef TASK_15_07_STDAFX_H
#include "Task_15_07_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	srand(time(NULL));
	Simple_window win(Point(50, 50), xmax, ymax, "Simple_window");
	MyHist hist(Point(100, 400), 300, 300);
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		hist.add(rand() % 100 + 1);
		hist.set_bar_fill_color(Color::green, i);
		hist.set_bar_color(Color::dark_green, i); 
		hist.set_bar_label(i);
		std::cout << i << '\t' << hist.get_idata(i) << '\n';
	}
	win.attach(hist);
	win.wait_for_button();
	return 0;
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}