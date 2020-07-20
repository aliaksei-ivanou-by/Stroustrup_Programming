#ifndef TASK_15_09_STDAFX_H
#include "Task_15_09_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	std::string input_file = "new_pairs.txt";
	ifstream ifs(input_file.c_str());
	if (!ifs)
	{
		error("can't open input file ", input_file);
	}
	int height;
	double n;
	vector<int> pairs_height;
	vector<double> pairs_n;
	vector<std::string> pairs_n_str;
	while (ifs >> height >> n)
	{
		pairs_height.push_back(height); // x
		pairs_n.push_back(n); // y
		std::ostringstream stream_n;
		stream_n << std::fixed;
		stream_n << std::setprecision(2);
		stream_n << n;
		std::string n_str = stream_n.str();
		pairs_n_str.push_back(n_str);
	}
	int height_max = 0;
	for (const auto& pair : pairs_height)
	{
		if (pair > height_max)
		{
			height_max = pair;
		}
	}

	Simple_window win(Point(50, 50), xmax, ymax, "Simple_window");
	MyHist hist(Point(100, 400), 300, 300);
	hist.set_x_label("height, m");
	hist.set_y_label("n, million");
	for (int i = 0; i < pairs_n.size(); ++i)
	{
		hist.add(pairs_n[i]);
		hist.set_bar_fill_color(Color::green, i);
		hist.set_bar_color(Color::dark_green, i);
		hist.set_bar_label("n=" + pairs_n_str[i] + ", h=" + std::to_string(pairs_height[i]),
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