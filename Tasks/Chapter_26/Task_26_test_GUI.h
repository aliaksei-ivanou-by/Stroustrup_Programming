#pragma once
#include <iostream>
#include "GUI/Graph.h"

enum class ShapeType
{
	Circle,
	Rectangle,
	Line
};

std::istream& operator>>(std::istream& inputStream, Point& point)
{
	char ch;
	std::string point_str;
	while (inputStream >> ch)
	{
		if (ch == '(')
		{
			break;
		}
		point_str += ch;
	}
	inputStream.unget();
	if (point_str != "Point")
	{
		throw std::runtime_error("Bad input Shape :: Point");
	}
	char delimeter1;
	char delimeter2;
	char delimeter3;
	int point_x;
	int point_y;
	inputStream >> delimeter1 >> point_x >> delimeter2 >> point_y >> delimeter3;
	if (delimeter1 != '(' ||
		delimeter2 != ',' ||
		delimeter3 != ')')
	{
		throw std::runtime_error("Bad input Point");
	}
	point = Point(point_x, point_y);
	return inputStream;
}

Graph_lib::Shape* getCircle(std::istream& inputStream, std::ostream& outputStream)
{
	char delimeter1;
	char delimeter2;
	char delimeter3;
	Point point;
	int radius;
	inputStream >> delimeter1 >> point >> delimeter2 >> radius >> delimeter3;
	if (delimeter1 != '(' ||
		delimeter2 != ',' ||
		delimeter3 != ')')
	{
		throw std::runtime_error("Bad input Shape::Circle");
	}
	outputStream << "Circle(Point(" << point.x << ", " << point.y << "), " << radius << ")\n";
	return new Graph_lib::Circle(point, radius);
}

Graph_lib::Shape* getRectangle(std::istream& inputStream, std::ostream& outputStream)
{
	char delimeter1;
	char delimeter2;
	char delimeter3;
	char delimeter4;
	Point point;
	int width;
	int height;
	inputStream >> delimeter1 >> point >> delimeter2 >> width >> delimeter3 >> height >> delimeter4;
	if (delimeter1 != '(' ||
		delimeter2 != ',' ||
		delimeter3 != ',' ||
		delimeter4 != ')')
	{
		throw std::runtime_error("Bad input Shape::Rectangle");
	}
	outputStream << "Rectangle(Point(" << point.x << ", " << point.y << "), " << width << ", " << height << ")\n";
	return new Graph_lib::Rectangle(point, width, height);
}

Graph_lib::Shape* getLine(std::istream& inputStream, std::ostream& outputStream)
{
	char delimeter1;
	char delimeter2;
	char delimeter3;
	Point point_first;
	Point point_second;
	inputStream >> delimeter1 >> point_first >> delimeter2 >> point_second >> delimeter3;
	if (delimeter1 != '(' ||
		delimeter2 != ',' ||
		delimeter3 != ')')
	{
		throw std::runtime_error("Bad input Shape::Line");
	}
	outputStream << "Line(Point(" << point_first.x << ", " << point_first.y <<
		"), Point(" << point_second.x << ", " << point_second.y << "))\n";
	return new Graph_lib::Line(point_first, point_second);
}

Shape* getShape(std::istream& inputStream, std::ofstream& outputStream)
{
	std::string shape_type;
	char ch;
	while (inputStream >> ch)
	{
		if (ch == '(')
		{
			inputStream.unget();
			break;
		}
		shape_type += ch;
	}
	if (shape_type == "Circle")
	{
		return getCircle(inputStream, outputStream);
	}
	else
	{
		if (shape_type == "Rectangle")
		{
			return getRectangle(inputStream, outputStream);
		}
		else
		{
			if (shape_type == "Line")
			{
				return getLine(inputStream, outputStream);
			}
			else
			{
				return nullptr;
			}
		}
	}
}