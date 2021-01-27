#ifndef TASK_24_10_STDAFX_H
#include "Task_24_10_stdafx.h"
#endif

int main()
try
{
	while (true)
	{
		int n;
		std::cout << "Enter biggest number for random : ";
		std::cin >> n;
		int d;
		std::cout << "Enter number of draws : ";
		std::cin >> d;
		std::vector<int> hist(n + 1);
		for (int i = 0; i < d; ++i)
		{
			++hist[rand_int(n)];
		}
		std::cout << "Distribution of numbers:\n";
		for (size_t i = 0; i != hist.size(); ++i)
		{
			std::cout << i << '\t';
			for (auto j = 0; j < hist[i]; ++j)
			{
				std::cout << '*';
			}
			std::cout << '\n';
		}
		std::cout << "\n\nAgain? 0 for exit, another for continue\n";
		int key = 0;
		std::cin >> key;
		if (key)
		{
			system("cls");
		}
		else
		{
			return 0;
		}
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