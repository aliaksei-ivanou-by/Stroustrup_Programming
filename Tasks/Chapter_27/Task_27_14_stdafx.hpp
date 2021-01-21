#ifndef TASK_27_14_STDAFX_HPP
#define TASK_27_14_STDAFX_HPP

#include <stdlib.h>

#endif

inline int rand_int(int min, int max)
{
	return rand() & (max - min) + min;
}

struct Statistics
{
	int min;
	int max;
	double mean;
	double median;
};

int cmp(const int* i, const int* j)
{
	return *i - *j;
}

double median(const int arr[], const int size)
{
	qsort(arr, size, sizeof(int), cmp);
	if (size % 2 == 1)
	{
		return arr[size / 2 + 1];
	}
	else
	{
		return (arr[size / 2] + arr[size / 2 + 1]) / 2;
	}
}

struct Statistics* get_statistics(const int arr[], const int size)
{
	struct Statistics* statistics = (struct Statistics*)malloc(sizeof(struct Statistics));
	statistics->min = arr[0];
	statistics->max = arr[0];
	double sum = 0;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] < statistics->min)
		{
			statistics->min = arr[i];
		}
		if (arr[i] > statistics->max)
		{
			statistics->max = arr[i];
		}
		sum += arr[i];
	}
	statistics->mean = sum / size;
	statistics->median = median(arr, size);
}