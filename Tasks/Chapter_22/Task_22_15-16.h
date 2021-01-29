#pragma once
#include <iostream>
#include <algorithm>
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

constexpr int maxX = 600;
constexpr int maxY = 600;
constexpr int offsetX = 50;
constexpr int offsetY = 50;
constexpr int lengthX = maxX - 2 * offsetX;
constexpr int nTicks = 9;
constexpr int minDistance = 60;

inline double& PI()
{
	static double pi = 3.14159265;
	return pi;
}

class Arrow : public Shape
{
public:
	Arrow(const Point& tail, const Point& tip)
	{
		add(tail);
		add(tip);
	}
	Arrow(const Point& tail, const Point& tip, const Color& line_color)
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
	void set_size(const int& s)
	{
		size = s;
	}
private:
	int size = 10;
	int delta = 20;
};

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
	ProgrammingLanguages(const int& yearToAdd, const std::vector<std::string>& ancestorsToAdd):
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
	friend std::istream& operator>>(std::istream& inputStream, std::pair<std::string, ProgrammingLanguages>& pair)
	{
		// pair format : (string,int,(string,string,...))
		const std::string error = "Bad input format. Must be '(string , int,(string,string,...))'";
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
			throw std::runtime_error(error);
		}
		while (inputStream.get(delimeter1) && delimeter1 != ',')
		{
			name.push_back(delimeter1);
		}
		inputStream >> year;
		if (!inputStream)
		{
			throw std::runtime_error(error);
		}
		inputStream >> delimeter2;
		if (delimeter2 != ',')
		{
			throw std::runtime_error(error);
		}
		inputStream >> delimeter3;
		if (delimeter3 != '(')
		{
			throw std::runtime_error(error);
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
						throw std::runtime_error(error);
					}
				}
			}
		}
		inputStream >> finish;
		if (finish != ')')
		{
			throw std::runtime_error(error);
		}
		ProgrammingLanguages ld(year, ancestors);
		pair = std::pair<std::string, ProgrammingLanguages>(name, ld);
		return inputStream;
	}
};

std::istream& operator>>(std::istream& inputStream, std::pair<std::string, int>& pair)
{
	// pair format : (string, int)
	std::string error = "Bad input format. Must be '(string , int)'";
	char start;
	char delimeter;
	char finish;
	std::string s;
	int i;
	inputStream >> start;
	if (!inputStream)
	{
		inputStream.clear(std::ios_base::failbit);
		return inputStream;
	}
	if (start != '(')
	{
		throw std::runtime_error(error);
	}
	while (inputStream.get(delimeter) && delimeter != ',')
	{
		s.push_back(delimeter);
	}
	inputStream >> i;
	if (!inputStream)
	{
		throw std::runtime_error(error);
	}
	inputStream >> finish;
	if (finish != ')')
	{
		throw std::runtime_error(error);
	}
	pair = std::pair<std::string, int>(s, i);
	return inputStream;
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

std::map<std::string, int> fileOpenInt(const std::string& fileName)
{
	std::ifstream inputFileStream(fileName);
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't open file");
	}
	std::pair<std::string, int> pair;
	std::map<std::string, int> data;
	while (inputFileStream >> pair)
	{
		data.insert(pair);
	}
	return data;
}

std::map<std::string, ProgrammingLanguages> fileOpenProgrammingLanguages(const std::string& fileName)
{
	std::ifstream inputFileStream(fileName);
	if (!inputFileStream)
	{
		throw std::runtime_error("Can't open file");
	}
	std::pair<std::string, ProgrammingLanguages> pair;
	std::map<std::string, ProgrammingLanguages> data;
	while (inputFileStream >> pair)
	{
		data.insert(pair);
	}
	return data;
}

std::pair<int, int> getYearRange(const std::map<std::string, int>& data)
{
	std::vector<int> vec;
	for (auto i : data)
	{
		vec.push_back(i.second);
	}
	auto min = min_element(std::begin(vec), std::end(vec));
	auto max = max_element(std::begin(vec), std::end(vec));
	return std::make_pair(*min, *max);
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

template<typename T>
void updateAxisY(Shape& s, const Vector_ref<T>& shapes)
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