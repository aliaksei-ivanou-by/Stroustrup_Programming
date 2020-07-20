#ifndef TASK_15_06_STDAFX_H
#include "Task_15_06_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	srand(time(NULL));
	Simple_window win(Point(100, 100), xmax, ymax, "Simple_window");
	MyHist hist(Point(100, 500), 300, 300);
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		hist.add(rand() % 100 + 1);
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