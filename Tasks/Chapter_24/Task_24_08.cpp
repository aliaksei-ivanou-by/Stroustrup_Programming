#include <iostream>
#include <random>
#include <numeric>
#include <iomanip>
#include "Matrix.h"
#include "MatrixIO.h"
#include "Task_24_Matrix_Additional.h"

int main()
try
{
	while (true)
	{
		std::cout << "Switch type of solution\n";
		std::cout << "Enter 1 for classical_gaussian_elimination\n";
		std::cout << "Enter 2 for pivotal_elimination\n";
		std::cout << "Enter another for exit\n";
		int type = 0;
		std::cin >> type;
		switch (type)
		{
		case(1):
		{
			std::cout << "Enter the dimension of the system of equations\n";
			int n;
			std::cin >> n;
			system("cls");
			solve_random_system_classical(n);
			std::cout << "\n\nAgain? 1 for continue, another to exit\n";
			int key = 0;
			std::cin >> key;
			if (key)
			{
				system("cls");
				break;
			}
			else
			{
				return 0;
			}
		}
		case(2):
		{
			std::cout << "Enter the dimension of the system of equations\n";
			int n;
			std::cin >> n;
			system("cls");
			solve_random_system_pivotal(n);
			std::cout << "\n\nAgain? 1 for continue, another to exit\n";
			int key = 0;
			std::cin >> key;
			if (key)
			{
				system("cls");
				break;;
			}
			else
			{
				return 0;
			}
		}
		default:
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