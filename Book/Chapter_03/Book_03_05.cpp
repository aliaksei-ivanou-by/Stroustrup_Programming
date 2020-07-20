// Ввод имени и отчества
#include "iostream"
int main()
{
	std::cout<<"Enter your name and middle name: \n";
	std::string first_name;
	std::string middle_name;
	std::cin>>first_name>>middle_name; // Считываем две строки
	std::string name=first_name+' '+middle_name; // Конкатенация строк
	std::cout<<"Hello, "<<name<<"!\n";
	return 0;
}
