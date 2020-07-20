// Ввод имени и возраста
#include "iostream"
int main()
{
	std::cout<<"Enter your name and age: \n";
	std::string first_name; // Строковая переменная
	int age; // Целочисленная переменная
	std::cin>>first_name; // Считываем строковое значение
	std::cin>>age; // Считываем целочисленное значение
	std::cout<<"Hello, "<<first_name<<" (age "<<age<<")!\n";
	return 0;
}
