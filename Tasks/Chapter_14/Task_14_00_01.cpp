#ifndef TASK_14_00_STDAFX_H
#include "Task_14_00_stdafx.h"
#endif

class B1
{
public:
	virtual void vf()
	{
		std::cout << "B1::vf()\n";
	}
	void f()
	{
		std::cout << "B1::f()\n";
	}
};

int main(int argc, char** argv)
try
{
	std::cout << "Step 1\nB1 b1\n";
	B1 b1;
	b1.vf();
	b1.f();
	return 0;
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