#ifndef TASK_26_12_FUNC_H
#define TASK_26_12_FUNC_H

#ifndef TASK_26_12_STDAFX_H
#include "Task_26_12_stdafx.h"
#endif

inline double rand_double(double min, double max);
void vector_generate_and_sort(
	const size_t& size,
	const double& min = std::numeric_limits<double>::min(),
	const double& max = std::numeric_limits<double>::max()
);

#endif
