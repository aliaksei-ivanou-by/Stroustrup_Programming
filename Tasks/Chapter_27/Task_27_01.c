#ifndef TASK_27_01_STDAFX_HPP
#include "Task_27_01_stdafx.hpp"
#endif

int main()
{
	char* ch1 = "abc";
	printf("length of \"%s\" is %d\n", ch1, my_strlen(ch1));

	char* ch2 = "xyz";
	int res = strcmp(ch1, ch2);
	if (res == 0)
	{
		printf("'%s' and '%s' are equal\n", ch1, ch2);
	}
	else
	{
		if (res < 0)
		{
			printf("'%s' is before '%s'\n", ch1, ch2);
		}
		else /* res > 0 */
		{
			printf("'%s' is after '%s'\n", ch1, ch2);
		}
	}

	char* ch3 = (char*)malloc(sizeof(char) * my_strlen(ch1));
	my_strcpy(ch3, ch1);
	printf("ch3 is \"%s\"\n", ch3);
}