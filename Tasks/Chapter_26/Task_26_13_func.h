#ifndef TASK_26_13_FUNC_H
#define TASK_26_13_FUNC_H

#ifndef TASK_26_13_STDAFX_H
#include "Task_26_13_stdafx.h"
#endif

inline int rand_int(const int& max);
std::string rand_string();
void vector_generate_and_sort(
	const size_t& size,
	const double& min = std::numeric_limits<double>::min(),
	const double& max = std::numeric_limits<double>::max()
);

#endif