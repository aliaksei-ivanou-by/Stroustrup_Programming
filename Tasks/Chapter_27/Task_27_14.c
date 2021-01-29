#include <stdlib.h>

struct Statistics
{
	int min;
	int max;
	double mean;
	double median;
};

inline int rand_int(int min, int max)
{
	return rand() & (max - min) + min;
}

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