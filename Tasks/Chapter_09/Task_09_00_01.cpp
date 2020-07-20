#include "iostream"
#include "Task_09_00_01_Chrono.h"

int main()
{
	std::cout<<"Chapter 9.4.1:\n";
	Chrono941::Date today;
	Chrono941::init_day(today, 1963, 5, 19);
	Chrono941::Date tomorrow=today;
	Chrono941::add_day(tomorrow, 1);
	std::cout<<"Today: "<<today<<"\n";
	std::cout<<"Tomorrow: "<<tomorrow<<"\n";
	Chrono941::Date invalid_date;
	Chrono941::init_day(invalid_date, 2020, 01, -5);
}
