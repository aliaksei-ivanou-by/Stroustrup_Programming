#include <iostream>
#include <vector>

struct X
{
	int val;
	void out(const std::string& s, int nv)
	{
		std::cerr << this << "\t->" << s << ": " << val
			<< " (" << nv << ")\n";
	}
	X()
	{
		out("X() ", 0);
		val = 0;
	}
	X(int v)
	{
		val = v;
		out("X(int) ", v);
	}
	X(const X& x)
	{
		val = x.val;
		out("X(X&) ", x.val);
	}
	X& operator=(const X& a)
	{
		out("X::operator=() ", a.val);
		val = a.val;
		return *this;
	}
	~X()
	{
		out("~X() ", 0);
	}
};

X glob(2);

X copy(X a)
{
	return a;
}

X copy2(X a)
{
	X aa = a;
	return aa;
}

X& ref_to(X& a)
{
	return a;
}

X* make(int i)
{
	X a(i);
	return new X(a);
}

struct XX
{
	X a;
	X b;
};

int main(int argc, char** argv)
try
{
	std::cout << "address\t\t\t->X(int) : 2 (2)\n\n";

	int i = 2;
	X loc{ 4 };
	std::cout << "address\t\t\t->X(int) : 4 (4)\n\n";

	X loc2{ loc };
	std::cout << "address\t\t\t->X(X&) : 4 (4)\n\n";

	loc = X{ 5 };
	std::cout << "address\t\t\t->X(int) : 5 (5)\n";
	std::cout << "address\t\t\t->X::operator=() : 4 (5)\n";
	std::cout << "address\t\t\t->~X() : 5 (0)\n\n";

	loc2 = copy(loc);
	std::cout << "address\t\t\t->X(X&) : 5 (5)\n";
	std::cout << "address\t\t\t->X(X&) : 5 (5)\n";
	std::cout << "address\t\t\t->~X() : 5 (0)\n";
	std::cout << "address\t\t\t->X::operator=() : 4 (5)\n";
	std::cout << "address\t\t\t->~X() : 5 (0)\n\n";

	loc2 = copy2(loc);
	std::cout << "address\t\t\t->X(X&) : 5 (5)\n";
	std::cout << "address\t\t\t->X(X&) : 5 (5)\n";
	std::cout << "address\t\t\t->~X() : 5 (0)\n";
	std::cout << "address\t\t\t->X::operator=() : 5 (5)\n";
	std::cout << "address\t\t\t->~X() : 5 (0)\n\n"; // 

	X loc3{ 6 };
	std::cout << "address\t\t\t->X(int) : 6 (6)\n\n";

	X& r = ref_to(loc);

	// OK
	delete make(7);
	std::cout << "address\t\t\t->X(int) : 7 (7)\n";
	std::cout << "address\t\t\t->X(X&) : 7 (7)\n";
	std::cout << "address\t\t\t->~X() : 7 (0)\n";
	std::cout << "address\t\t\t->~X() : 7 (0)\n\n";

	delete make(8);
	std::cout << "address\t\t\t->X(int) : 8 (8)\n";
	std::cout << "address\t\t\t->X(X&) : 8 (8)\n";
	std::cout << "address\t\t\t->~X() : 8 (0)\n";
	std::cout << "address\t\t\t->~X() : 8 (0)\n\n";

	std::vector<X> v(4);
	std::cout << "address\t\t\t->X() : 0 (0)\n";
	std::cout << "address\t\t\t->X() : 0 (0)\n";
	std::cout << "address\t\t\t->X() : 0 (0)\n";
	std::cout << "address\t\t\t->X() : 0 (0)\n\n";

	XX loc4;
	std::cout << "address\t\t\t->X() : ??? (0)\n";
	std::cout << "address\t\t\t->X() : 0 (0)\n\n";

	X* p = new X{ 9 };
	std::cout << "address\t\t\t->X(int) : 9 (9)\n\n";

	// OK
	delete p;
	std::cout << "address\t\t\t->~X() : 9 (0)\n\n";

	X* pp = new X[5];
	std::cout << "address\t\t\t->X() : ??? (0)\n";
	std::cout << "address\t\t\t->X() : ??? (0)\n";
	std::cout << "address\t\t\t->X() : ??? (0)\n";
	std::cout << "address\t\t\t->X() : ??? (0)\n";
	std::cout << "address\t\t\t->X() : ??? (0)\n\n";

	delete[] pp;
	std::cout << "address\t\t\t->~X() : 0 (0)\n";
	std::cout << "address\t\t\t->~X() : 0 (0)\n";
	std::cout << "address\t\t\t->~X() : 0 (0)\n";
	std::cout << "address\t\t\t->~X() : 0 (0)\n";
	std::cout << "address\t\t\t->~X() : 0 (0)\n\n";
	
	std::cout << "address\t\t\t->~X() : 0 (0)\n";
	std::cout << "address\t\t\t->~X() : 0 (0)\n";
	std::cout << "address\t\t\t->~X() : 0 (0)\n";
	std::cout << "address\t\t\t->~X() : 0 (0)\n";
	std::cout << "address\t\t\t->~X() : 0 (0)\n";
	std::cout << "address\t\t\t->~X() : 0 (0)\n";
	std::cout << "address\t\t\t->~X() : 6 (0)\n";
	std::cout << "address\t\t\t->~X() : 5 (0)\n";
	std::cout << "address\t\t\t->~X() : 5 (0)\n";
	std::cout << "address\t\t\t->~X() : 2 (0)\n\n";
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