#ifndef TASK_19_13_STDAFX
#include "Task_19_13_stdafx.h"
#endif

Tracer tracerGlobal{ "startGlobal", "finishGlobal" };

void initTracer1()
{
	Tracer tracer1{"startFunctionVoid", "finishFunctionVoid"};
	Tracer tracer2 = tracer1;
}

Tracer initTracer2()
{
	Tracer tracer{ "startFunctionReturnTracer", "finishFunctionReturnTracer" };
	return tracer;
}

class my_tracer
{
private:
	Tracer tracer;
public:
	my_tracer():
		tracer{"startClass", "finishClass"}
	{}
};

int main(int argc, char** argv)
try
{
	Tracer tracer1{ "start", "finish" };
	Tracer tracer2 = tracer1;
	initTracer1();
	Tracer tracer3 = initTracer2();
	Tracer* tracer4Ptr = new Tracer({"startPointer", "finishPointer"});
	delete tracer4Ptr;
	my_tracer tracer5;
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}