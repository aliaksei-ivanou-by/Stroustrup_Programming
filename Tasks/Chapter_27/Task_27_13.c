#ifndef TASK_27_13_STDAFX_HPP
#include "Task_27_13_stdafx.hpp"
#endif

int main()
{
	char* exit = "exit";
	printf("Enter '%s' for exit\n", exit);
	while (1)
	{
		char* ch = get_chars();
		if (!strcmp(ch, exit))
		{
			break;
		}
		printf("%s\n\n", ch);
	}
}