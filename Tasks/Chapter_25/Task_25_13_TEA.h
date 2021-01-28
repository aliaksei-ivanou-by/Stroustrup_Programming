#ifndef TASK_25_13_TEA_H
#define TASK_25_13_TEA_H

#ifndef TASK_25_13_STDAFX_H
#include "Task_25_13_stdafx.h"
#endif

void encipher(
	const unsigned long* const v,
	unsigned long* const w,
	const unsigned long* const k
);
void decipher(
	const unsigned long* const v,
	unsigned long* const w,
	const unsigned long* const k
);
void messageSent(
	const std::string& infile,
	const std::string& outfile,
	std::string& key
);
void messageReceive(
	const std::string& infile,
	const std::string& outfile,
	std::string& key
);

#endif