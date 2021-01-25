#ifndef TASK_20_03_ADDITIONAL_H
#define TASK_20_03_ADDITIONAL_H

#ifndef TASK_20_03_STDAFX_H
#include "Task_20_03_stdafx.h"
#endif

double* high(double* first, double* last);
double* high(double* myArray, size_t size);
double* high(std::vector<double>& myVector);
std::unique_ptr<double[]> get_from_jack(int* count);
std::unique_ptr<std::vector<double>> get_from_jill();

#endif