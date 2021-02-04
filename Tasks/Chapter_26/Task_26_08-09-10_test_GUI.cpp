#include <iostream>
#include <fstream>
#include "GUI/Graph.h"
#include "GUI/Simple_window.h"
#include "Task_26_test_GUI.h"

void compare(const std::string& fileName1, const std::string& fileName2)
{
	std::ifstream inputFileStream1{ fileName1 };
	std::string file1Contents{
		std::istreambuf_iterator<char>(inputFileStream1), std::istreambuf_iterator<char>()
	};
	std::ifstream inputFileStream2{ fileName2 };
	std::string file2Contents{
		std::istreambuf_iterator<char>(inputFileStream2), std::istreambuf_iterator<char>()
	};
	if (file1Contents == file2Contents)
	{
		std::cout << "input and output files are equal\n";
	}
	else
	{
		std::cout << "input and output files are NOT equal\n";
	}
}

int main()
try
{
	Simple_window win(Point(400, 100), 800, 600, "My window");
	std::string fileName = "Task_26_08_house.txt";
	std::string fileNameOutput = "Task_26_08_house_out.txt";
	std::ifstream inputFileStream(fileName);
	std::ofstream outputFileStream(fileNameOutput);
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't open file");
	}
	Vector_ref<Shape*> vec;
	while (true)
	{
		Shape* shape = getShape(inputFileStream, outputFileStream);
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
	inputFileStream.close();
	outputFileStream.close();
	
	compare(fileName, fileNameOutput);

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