#include <iostream>
#include <iomanip>

void f(int i, double fpd)
{
	std::cout << "i = " << i << '\t';
	char c = i;
	std::cout << "c = " << c << '\n';

	std::cout << "i = " << i << '\t';
	short s = i;
	std::cout << "s = " << s << '\n';

	std::cout << "i + i = " << i + i << '\t';
	i = i + i;
	std::cout << "i = i + i = " << i << '\n';

	std::cout << "i * i = " << i * i << '\t';
	long lg = i * i;
	std::cout << "lg = i * i = " << lg << '\n';

	std::cout << "fpd = " << fpd << '\t';
	float fps = fpd;
	std::cout << "fps = " << fps << '\n';

	std::cout << "fpd = " << fpd << '\t';
	i = fpd;
	std::cout << "i = " << i << '\n';

	std::cout << "i = " << i << '\t';
	fps = i;
	std::cout << "fps = " << fps << '\n';
}

void g()
{
	char ch = 0;
	for (int i = 0; i < 500; ++i)
	{
		std::cout << int(ch++) << '\t';
	}
}

int main()
try
{
	std::cout << "g()\n";
	g();

	std::cout << "f() max\n";
	int i = std::numeric_limits<int>::max();
	double d = std::numeric_limits<double>::max();
	f(i, d);

	std::cout << "f() min\n";
	i = std::numeric_limits<int>::min();
	d = std::numeric_limits<double>::min();
	f(i, d);
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