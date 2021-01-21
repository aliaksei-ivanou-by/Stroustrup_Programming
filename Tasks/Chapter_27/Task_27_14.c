#ifndef TASK_27_14_STDAFX_HPP
#include "Task_27_14_stdafx.hpp"
#endif

int main()
{
	srand(time(NULL));
	const int n = 5;
	int arr[5];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand_int(INT_MIN, INT_MAX);
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	struct Statistics* statistics = get_statistics(arr, n);

	printf("min: %d\nmax: %d\nmean: %lf\nmedian: %lf\n",
		statistics->min,
		statistics->max,
		statistics->mean,
		statistics->median);
}