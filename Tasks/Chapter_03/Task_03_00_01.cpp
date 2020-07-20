// Ввод имени и возраста (2 версия)
#include "iostream"
int main()
{
	std::cout<<"Enter your name and age: \n";
	std::string first_name="???"; // Строковая переменная
	double age=-1; // Целочисленная переменная
	std::cin>>first_name>>age; // Считываем строковое значение, а затем целочисленное значение
	std::cout<<"Hello, "<<first_name<<" (age "<<age*12<<")!\n";
	return 0;
}
