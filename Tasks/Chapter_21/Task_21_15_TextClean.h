#ifndef TASK_21_15_TEXTCLEAN_H
#define TASK_21_15_TEXTCLEAN_H

#ifndef TASK_21_15_STDAFX_H
#include "Task_21_15_stdafx.h"
#endif

void fileOpen(std::ifstream& inputFileStream, const std::string& fileName);
void textCleanToLower(std::ifstream& inputFileStream, std::ostringstream& outputStringStream, char& ch);
void textCleanRemoveAbbreviations(std::istringstream& inputStringStream, std::map<std::string, int>& data, std::string& str);
void textCleanRemovePlurals(std::map<std::string, int>& data);
std::map<std::string, int> textClean(const std::string& fileName);

#endif