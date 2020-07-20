#include "iostream"
#include "Task_09_00_02_Chrono.h"

int main()
{
    std::cout<<"Chapter 9.4.2:\n";
    Chrono942::Date today(1963, 5, 19);
    Chrono942::Date tomorrow=today;
    tomorrow.add_day(1);
    std::cout<<"Today: "<<today<<"\n";
    std::cout<<"Tomorrow: "<<tomorrow<<"\n";
    Chrono942::Date invalid_date=Chrono942::Date(2020, 01, -21);
}
