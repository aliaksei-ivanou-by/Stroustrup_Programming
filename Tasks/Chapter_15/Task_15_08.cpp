#ifndef TASK_15_08_STDAFX_H
#include "Task_15_08_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	std::string input_file = "pairs.txt";
	ifstream ifs(input_file.c_str());
	if (!ifs)
	{
		error("can't open input file ", input_file);
	}
	int height;
	int n;
	vector<int> pairs_height;
	vector<int> pairs_n;
	while (ifs >> height >> n)
	{
		pairs_height.push_back(height); // x
		pairs_n.push_back(n); // y
	}
	int height_max = 0;
	for (int i = 0; i < pairs_height.size(); ++i)
	{
		if (pairs_height[i] > height_max)
			height_max = pairs_height[i];
	}

	Simple_window win(Point(50, 50), xmax, ymax, "Simple_window");
	MyHist hist(Point(100, 400), 300, 300);
	hist.set_x_label("height");
	hist.set_y_label("n");
	for (int i = 0; i < pairs_n.size(); ++i)
	{
		hist.add(pairs_n[i]);
		hist.set_bar_fill_color(Color::green, i);
		hist.set_bar_color(Color::dark_green, i); 
		hist.set_bar_label("n=" + std::to_string(pairs_n[i]) + ", h=" + std::to_string(pairs_height[i]),
			i);
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