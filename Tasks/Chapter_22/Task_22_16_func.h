#ifndef TASK_22_16_FUNC_H
#define TASK_22_16_FUNC_H

#ifndef TASK_22_16_STDAFX_H
#include "Task_22_16_stdafx.h"
#endif

inline double& PI();

constexpr int maxX = 600;
constexpr int maxY = 600;
constexpr int offsetX = 50;
constexpr int offsetY = 50;
constexpr int lengthX = maxX - 2 * offsetX;
constexpr int nTicks = 9;
constexpr int minDistance = 60;

class Arrow : public Shape
{
public:
	Arrow(const Point& tail, const Point& tip);
	Arrow(const Point& tail, const Point& tip, const Color& line_color);
	void draw_lines() const;
	void set_size(const int& s);
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
	ProgrammingLanguages();
	ProgrammingLanguages(const int& yearToAdd, const std::vector<std::string>& ancestorsToAdd);
	int getYear() const;
	std::vector<std::string> getAncestors() const;
	friend std::istream& operator>>(std::istream& inputStream, std::pair<std::string, int>& pair);
};

void setArrows(Simple_window& win,
	const std::map<std::string, ProgrammingLanguages>& data,
	const Vector_ref<Text>& labels,
	const std::vector<std::string>& labelsString,
	Vector_ref<Arrow>& arrows);
std::map<std::string, ProgrammingLanguages> fileOpen(const std::string& fileName);
std::pair<int, int> getYearRange(const std::map<std::string, ProgrammingLanguages>& data);
void updateAxisY(Shape& s, const Vector_ref<Text>& shapes);

#endif