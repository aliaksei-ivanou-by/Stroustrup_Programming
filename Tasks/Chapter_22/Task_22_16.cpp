#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"
#include "Task_22_15-16.h"

int main()
try
{
	std::string fileName = "Task_22_16.txt";
	std::map<std::string, ProgrammingLanguages> data = fileOpenProgrammingLanguages(fileName);
	std::pair<int, int> dataYearRange = getYearRange(data);

	double delta = (dataYearRange.second - dataYearRange.first) / static_cast<double>(nTicks);
	std::ostringstream oss;
	for (int i = 0; i <= nTicks; ++i)
	{
		oss << std::left << std::setw(10) << int(dataYearRange.first + i * delta);
	}
	std::string labelX = oss.str();

	Simple_window win(Point(50, 50), maxX, maxY, "Programming languages");
	
	Axis axisX(Axis::x, Point(offsetX, maxY - offsetY), lengthX, nTicks, labelX);
	axisX.label.move(-maxX / 3.5, 0);
	axisX.set_color(Color::black);
	win.attach(axisX);

	Vector_ref<Text> labels;
	std::vector<std::string> labelsString;

	for (auto i = data.begin(); i != data.end(); ++i)
	{
		double ratio = (i->second.getYear() - dataYearRange.first) / 
			static_cast<double>(dataYearRange.second - dataYearRange.first);
		int x = offsetX + ratio * (maxX - 2 * offsetX);
		Text* label = new Text{ Point{ x, maxY - 2 * offsetY }, i->first };
		updateAxisY(*label, labels);
		label->set_color(Color::red);
		labels.push_back(label);
		labelsString.push_back(label->label());
		win.attach(labels[labels.size() - 1]);
	}

	Vector_ref<Arrow> arrows;
	
	setArrows(win, data, labels, labelsString, arrows);

	win.wait_for_button();
	
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