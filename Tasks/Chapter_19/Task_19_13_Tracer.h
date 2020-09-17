#ifndef TASK_19_13_TRACER_H
#define TASK_19_13_TRACER_H

#ifndef TASK_19_13_STDAFX_H
#include "Task_19_13_stdafx.h"
#endif

class Tracer
{
private:
	std::string stringStart;
	std::string stringFinish;
public:
	Tracer(const std::string& stringStart, const std::string& stringFinish);
	Tracer(const Tracer& tracer);
	Tracer& operator=(const Tracer& tracer);
	Tracer(Tracer&& tracer);
	Tracer& operator=(Tracer&& tracer);
	~Tracer();
};

#endif