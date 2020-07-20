#include "iostream"
#include "Task_09_00_04_Chrono.h"

int main()
{
    std::cout<<"Chapter 9.7.1:\n";
    Chrono971::Date today(1963, Chrono971::Date::may, 19);
    Chrono971::Date tomorrow=today;
    tomorrow.add_day(1);
    std::cout<<"Today: "<<today<<"\n";
    std::cout<<"Tomorrow: "<<tomorrow<<"\n";
    Chrono971::Date invalid_date=Chrono971::Date(2020, Chrono971::Date::jan, -21);
}
