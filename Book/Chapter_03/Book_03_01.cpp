// Считать и записать имя
#include "iostream"
int main()
{
	std::cout<<"Enter your name (and enter 'enter'): \n";
	std::string first_name; // first_name - переменная типа string
	std::cin>>first_name; // Считываем символы в first_name
	std::cout<<"Hello, "<<first_name<<"!\n";
	return 0;
}
