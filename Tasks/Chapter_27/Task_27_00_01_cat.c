#ifndef TASK_27_00_01_STDAFX_HPP
#include "Task_27_00_01_stdafx.hpp"
#include "Task_27_00_01_cat.hpp"
#endif

char* cat(const char* id, const char* addr)
{
	int idLength = strlen(id); /* function strlen() works once */
	int idAddr = strlen(addr); /* function strlen() works once */
	int sz = idLength + idAddr + 2; /* +2 - for addition symbol and end of char* */
	char* res = 0;
	res = (char*)malloc(sz);
	if (!res)
	{
		perror("Can't allocate memory");
	}
	strcpy(res, id);
	res[idLength] = '@'; /* NOT idLength + 1 */
	strcpy(res + idLength + 1, addr); /* NOT res + idLength + 2 */
	res[sz - 1] = 0; /* end of char* */
	return res;
}
