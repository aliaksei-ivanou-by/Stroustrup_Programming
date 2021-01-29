#include <iostream>
#include <fstream>
#include <iomanip>
#include "Task_25_TEA.h"

int main()
try
{
	std::string fileName1;
	std::string fileName2;
	std::string key;

	while (true)
	{
		system("cls");
		std::cout << "Message encoding program (Tiny Encryption Algorithm\n";
		std::cout << "If you want to send message - enter 1\n";
		std::cout << "If you want to receive message - enter 2\n";
		std::cout << "If you want to send message - enter another key\n";
		int type = 0;
		std::cin >> type;
		switch (type)
		{
		case(1): // send
		{
			std::cout << "Enter input file name : ";
			std::cin >> fileName1;
			std::cout << "Enter output file name : ";
			std::cin >> fileName2;
			std::cout << "Enter key file name : ";
			std::cin >> key;
			messageSent(fileName1, fileName2, key);
			std::cout << "The message is encrypted\n";
			std::cout << "You want to continue or exit? Enter 1 for continue, another key for exit\n";
			int is_exit = 0;
			std::cin >> is_exit;
			if (is_exit != 1)
			{
				return 0;
			}
			break;
		}
		case(2): // receive
		{
			std::cout << "Enter input file name : ";
			std::cin >> fileName1;
			std::cout << "Enter output file name : ";
			std::cin >> fileName2;
			std::cout << "Enter key file name : ";
			std::cin >> key;
			messageReceive(fileName1, fileName2, key);
			std::cout << "The message is deciphered\n";
			std::cout << "You want to continue or exit? Enter 1 for continue, another key for exit\n";
			int is_exit = 0;
			std::cin >> is_exit;
			if (is_exit != 1)
			{
				return 0;
			}
			break;
		}
		default:
		{
			return 0;
		}
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