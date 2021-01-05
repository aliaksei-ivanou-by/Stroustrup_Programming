#ifndef TASK_22_16_STDAFX_H
#define TASK_22_16_STDAFX_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

#endif

inline double& PI()
{
	static double pi = 3.14159265;
	return pi;
}

class Arrow : public Shape
{
public:
	Arrow(Point tail, Point tip)
	{
		add(tail);
		add(tip);
	}
	Arrow(Point tail, Point tip, Color line_color)
	{
		add(tail);
		add(tip);
		set_color(line_color);
	}
	void draw_lines() const
	{
		int diff_x = point(1).x - point(0).x;
		int diff_y = point(1).y - point(0).y;
		double angle = atan2(diff_y, diff_x) * 180 / PI();
		double x1 = point(1).x - cos((angle - delta) * PI() / 180) * size;
		double y1 = point(1).y - sin((angle - delta) * PI() / 180) * size;
		double x2 = point(1).x - cos((angle + delta) * PI() / 180) * size;
		double y2 = point(1).y - sin((angle + delta) * PI() / 180) * size;
		Graph_lib::Polygon head;
		head.add(point(1));
		head.add(Point(int(x1), int(y1)));
		head.add(Point(int(x2), int(y2)));
		head.set_fill_color(color());
		head.draw_lines();
		Shape::draw_lines();
	}
	void set_size(int s)
	{
		size = s;
	}
private:
	int size = 10;
	int delta = 20;
};

constexpr int maxX = 600;
constexpr int maxY = 600;
constexpr int offsetX = 50;
constexpr int offsetY = 50;
constexpr int lengthX = maxX - 2 * offsetX;
constexpr int nTicks = 9;
constexpr int minDistance = 60;

class ProgrammingLanguages
{
private:
	int year;
	std::vector<std::string> ancestors;
public:
	ProgrammingLanguages():
		year{ 0 },
		ancestors{ }
	{}
	ProgrammingLanguages(int yearToAdd, std::vector<std::string> ancestorsToAdd) :
		year{ yearToAdd },
		ancestors{ ancestorsToAdd }
	{}
	int getYear() const
	{
		return year;
	}
	std::vector<std::string> getAncestors() const
	{
		return ancestors;
	}
	friend std::istream& operator>>(std::istream& inputStream, std::pair<std::string, int>& pair);
};

std::istream& operator>>(std::istream& inputStream, std::pair<std::string, ProgrammingLanguages>& pair)
{
	// pair format : (string,int,(string,string,...))
	std::string error = "Bad input format. Must be '(string , int,(string,string,...))'";
	char start;
	char delimeter1;
	char delimeter2;
	char delimeter3;
	char delimeter4;
	char finish;
	std::string name;
	int year;

	inputStream >> start;
	if (!inputStream)
	{
		inputStream.clear(std::ios_base::failbit);
		return inputStream;
	}
	if (start != '(')
	{
		throw(error);
	}
	while (inputStream.get(delimeter1) && delimeter1 != ',')
	{
		name.push_back(delimeter1);
	}
	inputStream >> year;
	if (!inputStream)
	{
		throw(error);
	}
	inputStream >> delimeter2;
	if (delimeter2 != ',')
	{
		throw(error);
	}
	inputStream >> delimeter3;
	if (delimeter3 != '(')
	{
		throw(error);
	}
	bool key = true;
	std::vector<std::string> ancestors;
	while (key)
	{
		std::string ancestor;
		while (inputStream.get(delimeter4) && delimeter4 != ',' && delimeter4 != ')')
		{
			ancestor.push_back(delimeter4);
		}
		ancestors.push_back(ancestor);
		while (true)
		{
			if (delimeter4 == ')')
			{
				key = false;
				break;
			}
			else
			{
				if (delimeter4 == ',')
				{
					break;
				}
				else
				{
					throw(error);
				}
			}
		}
	}

	inputStream >> finish;
	if (finish != ')')
	{
		throw(error);
	}

	ProgrammingLanguages ld(year, ancestors);
	pair = std::pair<std::string, ProgrammingLanguages>(name, ld);
	return inputStream;
}

std::map<std::string, ProgrammingLanguages> fileOpen(const std::string& fileName)
{
	std::ifstream inputFileStream(fileName);
	if (!inputFileStream)
	{
		throw ("Can't open file ", fileName);
	}
	std::pair<std::string, ProgrammingLanguages> pair;
	std::map<std::string, ProgrammingLanguages> data;
	while (inputFileStream >> pair)
	{
		data.insert(pair);
	}
	return data;
}

std::pair<int, int> getYearRange(const std::map<std::string, ProgrammingLanguages>& data)
{
	std::vector<int> vec;
	for (auto i : data)
	{
		vec.push_back(i.second.getYear());
	}	
	auto min = min_element(std::begin(vec), std::end(vec));
	auto max = max_element(std::begin(vec), std::end(vec));
	return std::make_pair(*min, *max);
}

void updateAxisY(Shape& s, const Vector_ref<Text>& shapes)
{
	if (shapes.size() == 0)
	{
		return;
	}
	double minDist = 0;
	std::vector<double> distances(shapes.size());
	bool key = true;
	while (key)
	{
		for (int i = 0; i < shapes.size(); ++i)
		{
			distances[i] = sqrt(
				pow(shapes[i].point(0).x - s.point(0).x, 2) + 
				pow(shapes[i].point(0).y - s.point(0).y, 2));
		}
		minDist = *min_element(distances.begin(), distances.end());
		if (minDist < minDistance)
		{
			s.move(0, -(minDistance + 5));
		}
		else
		{
			key = false;
		}
	}
}

void setArrows(Simple_window& win,
	const std::map<std::string, ProgrammingLanguages>& data,
	const Vector_ref<Text>& labels,
	const std::vector<std::string>& labelsString,
	Vector_ref<Arrow>& arrows)
{
	for (auto p = data.begin(); p != data.end(); ++p)
	{
		for (int i = 0; i < p->second.getAncestors().size(); ++i)
		{
			Point p0;
			Point p1;
			for (int j = 0; j < labels.size(); ++j)
			{
				if (labelsString[j] == p->second.getAncestors()[i])
				{
					p0 = Point{ labels[j].point(0).x, labels[j].point(0).y };
				}
				if (labelsString[j] == p->first)
				{
					p1 = Point{ labels[j].point(0).x, labels[j].point(0).y };
				}
				if (p0 != Point(0, 0) && p1 != Point(0, 0))
				{
					break;
				}
			}
			if (p0 != Point(0, 0) && p1 != Point(0, 0))
			{
				arrows.push_back(new Arrow(p0, p1));
				for (auto i = 0; i < arrows.size(); ++i)
				{
					arrows[i].set_color(Color::black);
					arrows[i].set_size(6);
				}
				win.attach(arrows[arrows.size() - 1]);
			}
		}
	}
}