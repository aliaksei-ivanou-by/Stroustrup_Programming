#include "iostream"

void f(const int n)
{
	std::cout<<n<<"\n";
}

int main()
{
	try
	{
		int n=10;
		f(n);
	}
	catch (const char* msg)
	{
		std::cout<<msg;
	}
}
