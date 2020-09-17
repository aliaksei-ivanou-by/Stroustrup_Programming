#ifndef TASK_19_12_STDAFX
#include "Task_19_12_stdafx.h"
#include "Task_19_12_File_handle.h"
#endif

File_handle::File_handle(const std::string&& fileName):
	fileStream{ fileName },
	fileName{ fileName }
{
	std::cout << "File (" << fileName << ") is opened\n";
}

File_handle::~File_handle()
{
	fileStream.close();
	std::cout << "File (" << fileName << ") is closed\n";
}
