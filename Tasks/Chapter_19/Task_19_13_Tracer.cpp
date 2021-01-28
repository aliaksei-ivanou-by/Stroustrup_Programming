#ifndef TASK_19_13_STDAFX_H
#include "Task_19_13_stdafx.h"
#include "Task_19_13_Tracer.h"
#endif

Tracer::Tracer(const std::string& stringStart, const std::string& stringFinish) :
	stringStart{ stringStart },
	stringFinish{ stringFinish }
{
	std::cout << "Constructor\t" << stringStart << '\n';
}

Tracer::Tracer(const Tracer& tracer) :
	stringStart{ tracer.stringStart },
	stringFinish{ tracer.stringFinish }
{
	std::cout << "Copy Constructor\n";
}

Tracer& Tracer::operator=(const Tracer& tracer)
{
	stringStart = tracer.stringStart;
	stringFinish = tracer.stringFinish;
	std::cout << "Operator= Copy Constructor\n";
	return *this;
}

Tracer::Tracer(Tracer&& tracer) :
	stringStart{ tracer.stringStart },
	stringFinish{ tracer.stringFinish }
{
	tracer.stringStart = "";
	tracer.stringFinish = "";
	std::cout << "Move Constructor\n";
}

Tracer& Tracer::operator=(Tracer&& tracer)
{
	stringStart = tracer.stringStart;
	stringFinish = tracer.stringFinish;
	tracer.stringStart = "";
	tracer.stringFinish = "";
	std::cout << "Operator= Move Constructor\n";
	return *this;
}

Tracer::~Tracer()
{
	std::cout << "Destructor\t" << stringFinish << '\n';
}