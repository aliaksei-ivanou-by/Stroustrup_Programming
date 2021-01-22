#ifndef TASK_27_08_STDAFX_HPP
#include "Task_27_08_stdafx.hpp"
#endif

int main()
{
	const int size = 95;
	int arr_int[95];
	char arr_ch[95];

	for (int i = 0; i < size; ++i)
	{
		arr_int[i] = i + 32;
		arr_ch[i] = (char)arr_int[i];
		printf("%d\t%c\n", arr_int[i], arr_ch[i]);
	}

	printf("\nSorted\n");
	qsort(arr_ch, size, sizeof(char), ascending);
	for (int i = 0; i < size; ++i)
	{
		printf("%d\t%c\n", (int)arr_ch[i], arr_ch[i]);
	}
}