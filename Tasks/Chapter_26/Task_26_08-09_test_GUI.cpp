#include <iostream>
#include <fstream>
#include "GUI/Graph.h"
#include "GUI/Simple_window.h"
#include "Task_26_test_GUI.h"

int main()
try
{
	Simple_window win(Point(400, 100), 800, 600, "My window");
	std::string fileName = "Task_26_08_house.txt";
	std::ifstream inputFileStream(fileName);
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't open file");
	}
	Vector_ref<Shape*> vec;
	while (true)
	{
		Shape* shape = getShape(inputFileStream);
		if (shape)
		{
			shape->set_color(Color::black);
			vec.push_back(shape);
			win.attach(*vec[vec.size() - 1]);
		}
		else
		{
			break;
		}
	}
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