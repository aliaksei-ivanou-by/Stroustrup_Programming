#include "iostream"

#include "Task_09_10_Chrono.h"

int main()
{
    Chrono::Date date1(2020, Chrono::Date::feb, 28);
    Chrono::Date date2(2019, Chrono::Date::feb, 28);
    if (Chrono::leapyear(date1.year()))
    	std::cout<<"date1 in leap year\n";
    else
    	std::cout<<"date1 isn't in leap year\n";
    if (Chrono::leapyear(date2.year()))
    	std::cout<<"date2 in leap year\n";
    else
    	std::cout<<"date2 isn't in leap year\n";
}
