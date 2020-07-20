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
	virtual void pvf() = 0;
};

class D1 : public B1
{
public:
	void vf()
	{
		std::cout << "D1::vf()\n";
	}
	void f()
	{
		std::cout << "D1::f()\n";
	}
};

class D2 : public D1
{
public:
	void pvf()
	{
		std::cout << "D2::pvf()\n";
	}
};

int main(int argc, char** argv)
try
{
	std::cout << "Step 6\nD2 d2\n";
	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();
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