#ifndef TASK_25_00_01_STDAFX_H
#include "Task_25_00_01_stdafx.h"
#endif

int main()
try
{
	Device device("DeviceName");
	Message* get_input(Device&);
	constexpr int count = 10;
	int counter = count;
	int counterMax = counter;
	while (counter)
	{
		std::cout << "Iteration " << counterMax - counter + 1 << '\n';
		Node* n1 = new Node;
		std::cout << "n1 address =\t" << n1 << "\t\tsizeof(n1) =\t" << sizeof(n1) << '\n';
		Node* n2 = new Node;
		std::cout << "n2 address =\t" << n2 << "\t\tsizeof(n2) =\t" << sizeof(n2) << '\n';
		Message* p = get_input(device);
		std::cout << "p address =\t" << p << "\t\tsizeof(p) =\t" << sizeof(p) << '\n';
		std::cout << "\n\n";
		delete p;
		--counter;
	}

	counter = count;
	counterMax = counter;
	while (counter)
	{
		std::cout << "Iteration " << counterMax - counter + 1 << '\n';
		Node* n1 = new Node;
		std::cout << "n1 address =\t" << n1 << "\t\tsizeof(n1) =\t" << sizeof(n1) << '\n';
		Node* n2 = new Node;
		std::cout << "n2 address =\t" << n2 << "\t\tsizeof(n2) =\t" << sizeof(n2) << '\n';
		delete n2;
		Message* p = get_input(device);
		std::cout << "p address =\t" << p << "\t\tsizeof(p) =\t" << sizeof(p) << '\n';
		std::cout << "\n\n";
		--counter;
	}
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