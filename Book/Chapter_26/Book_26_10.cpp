#include <chrono>
#include <iostream>

using namespace std;

int main()
{
	int n = 10000000;
	auto t1 = system_clock::now();
	for (int i = 0; i < n; i++)
	{
		do_something();
	}
	auto t2 = system_clock::now();
	cout << "Time do_something() " << n << " times : " << 
		duration_cast<milliseconds>(t2 - t1).count() << "ms\n";
}