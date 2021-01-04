#ifndef TASK_19_12_FILE_HANDLE_H
#define TASK_19_12_FILE_HANDLE_H

#ifndef TASK_19_12_STDAFX_H
#include "Task_19_12_stdafx.h"
#endif

class File_handle
{
private:
	std::fstream fileStream;
	std::string fileName;
public:
	File_handle(const std::string& fileName);
	~File_handle();
};

#endif