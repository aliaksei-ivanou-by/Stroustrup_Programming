#ifndef TASK_23_07_FINDBANKCARDS_H
#define TASK_23_07_FINDBANKCARDS_H

#ifndef TASK_23_07_STDAFX_H
#include "Task_23_07_stdafx.h"
#endif

bool checkBankCard(const std::sub_match<std::string::const_iterator>& cardMatch);
bool findBankCards(const std::string& line, std::match_results<std::string::const_iterator>& m);

#endif
