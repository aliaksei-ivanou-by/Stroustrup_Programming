#ifndef TASK_14_00_STDAFX_H
#include "Task_14_00_stdafx.h"
#endif

class B2
{
public:
	virtual void pvf() = 0;
};

class D21 : public B2
{
public:
	std::string str;
	void pvf()
	{
		std::cout << str << '\n';
	}
};

class D22 : public B2
{
public:
	int n;
	void pvf()
	{
		std::cout << n << '\n';
	}
};

void f(B2& b2)
{
	b2.pvf();
}

int main(int argc, char** argv)
try
{
	std::cout << "Step 7\n";
	D21 d21;
	D22 d22;
	d21.str = "D21 d21";
	d22.n = 22;
	f(d21);
	f(d22);
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