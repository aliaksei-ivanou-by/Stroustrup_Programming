#include "iostream"

class A
{
public:
	A()
	{
		std::cout << "A created" << '\n';
	}
	virtual ~A()
	{
		std::cout << "A destroyed" << '\n';
	}
};

class B : public A
{
public:
	B()
	{
		std::cout << "B created" << '\n';
	}
	~B()
	{
		std::cout << "B destroyed" << '\n';
	}
};

int main()
{
	A* p = new B; // A created, B created

	std::cout << '\n';

	delete p; // B destroyed, A destroyed

	return 0;
}
