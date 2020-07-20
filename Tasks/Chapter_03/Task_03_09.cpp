#include "iostream"
int main()
{
	std::cout<<"Please, enter a number in words : \n";
	std::string num=" ";
	std::cin>>num;
	if (num=="zero")
		std::cout<<num<<" = 0\n";
	else
		if (num=="one")
			std::cout<<num<<" = 1\n";
		else
			if (num=="two")
				std::cout<<num<<" = 2\n";
			else
				if (num=="three")
					std::cout<<num<<" = 3\n";
				else
					if (num=="four")
						std::cout<<num<<" = 4\n";
					else
						std::cout<<"I don't know this number!\n";
	return 0;
}
