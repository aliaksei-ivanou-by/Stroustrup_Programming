#ifndef TASK_22_15_FUNC_H
#define TASK_22_15_FUNC_H

#ifndef TASK_22_15_STDAFX_H
#include "Task_22_15_stdafx.h"
#endif

constexpr int maxX = 600;
constexpr int maxY = 600;
constexpr int offsetX = 50;
constexpr int offsetY = 50;
constexpr int lengthX = maxX - 2 * offsetX;
constexpr int nTicks = 9;
constexpr int minDistance = 60;

std::istream& operator>>(std::istream& inputStream, std::pair<std::string, int>& pair);
std::map<std::string, int> fileOpen(const std::string& fileName);
std::pair<int, int> getYearRange(const std::map<std::string, int>& data);
void updateAxisY(Shape& s, const Vector_ref<Shape>& shapes);

#endif