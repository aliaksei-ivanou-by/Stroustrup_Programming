#ifndef TASK_22_15_STDAFX_H
#define TASK_22_15_STDAFX_H

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

constexpr int maxX = 600;
constexpr int maxY = 600;
constexpr int offsetX = 50;
constexpr int offsetY = 50;
constexpr int lengthX = maxX - 2 * offsetX;
constexpr int nTicks = 9;
constexpr int minDistance = 60;

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
		throw (error);
	}
	while (inputStream.get(delimeter) && delimeter != ',')
	{
		s.push_back(delimeter);
	}
	inputStream >> i;
	if (!inputStream)
	{
		throw (error);
	}
	inputStream >> finish;
	if (finish != ')')
	{
		throw(error);
	}
	pair = std::pair<std::string, int>(s, i);
	return inputStream;
}

std::map<std::string, int> fileOpen(const std::string& fileName)
{
	std::ifstream inputFileStream(fileName);
	if (!inputFileStream)
	{
		throw ("Can't open file ", fileName);
	}
	std::pair<std::string, int> pair;
	std::map<std::string, int> data;
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

void updateAxisY(Shape& s, const Vector_ref<Shape>& shapes)
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