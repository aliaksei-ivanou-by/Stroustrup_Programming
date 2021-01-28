#ifndef TASK_25_00_07_STDAFX_H
#include "Task_25_00_07_stdafx.h"
#endif

int main()
try
{
	// 1
	int value_1_1 = 1;
	for (int i = 0; i < sizeof(value_1_1) * 8; ++i)
	{
		std::cout << value_1_1 << ' ';
		value_1_1 <<= 1;
	}

	std::cout << "\n\n";

	// 2
	unsigned int value_2_1 = 1;
	for (int i = 0; i < sizeof(value_2_1) * 8; ++i)
	{
		std::cout << value_2_1 << ' ';
		value_2_1 <<= 1;
	}

	// 3
	std::vector<short unsigned int> vec1;
	vec1.push_back(0xffff);
	vec1.push_back(0x0001);
	vec1.push_back(0x8000);
	vec1.push_back(0x00ff);
	vec1.push_back(0xff00);
	vec1.push_back(0x5555);
	vec1.push_back(0xaaaa);
	
	std::cout << "\n\n";

	// 4
	for (const auto& i : vec1)
	{
		std::cout <<
			std::dec << std::setw(5) << i << ' ' <<
			std::hex << std::setw(4) << i << ' ' <<
			std::bitset<16>(i) << '\n';
	}

	std::cout << "\n\n";

	// 5
	std::vector<short unsigned int> vec2;
	vec2.push_back(~0);
	vec2.push_back(1);
	vec2.push_back(1 << 15);
	vec2.push_back(1 << 0 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5 | 1 << 6 | 1 << 7);
	vec2.push_back(~(1 << 0 | 1 << 1 | 1 << 2 | 1 << 3 | 1 << 4 | 1 << 5 | 1 << 6 | 1 << 7));
	vec2.push_back(1 << 0 | 1 << 2 | 1 << 4 | 1 << 6 | 1 << 8 | 1 << 10 | 1 << 12 | 1 << 14);
	vec2.push_back(~(1 << 0 | 1 << 2 | 1 << 4 | 1 << 6 | 1 << 8 | 1 << 10 | 1 << 12 | 1 << 14));

	for (const auto& i : vec2)
	{
		std::cout <<
			std::dec << std::setw(5) << i << ' ' <<
			std::hex << std::setw(4) << i << ' ' <<
			std::bitset<16>(i) << '\n';
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