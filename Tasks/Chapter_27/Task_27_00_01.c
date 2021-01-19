#ifndef TASK_27_00_01_STDAFX_HPP
#include "Task_27_00_01_stdafx.hpp"
#endif

int main()
{
	char* id = "aliaksei.ivanou.by";
	char* domen = "icloud.com";
	char* email = cat(id, domen);
	printf("%s\n", email);
}