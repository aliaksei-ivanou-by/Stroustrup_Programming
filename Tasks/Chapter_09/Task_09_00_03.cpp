#include "iostream"
#include "Task_09_00_03_Chrono.h"

int main()
{
    std::cout<<"Chapter 9.4.3:\n";
    Chrono943::Date today(1963, 5, 19);
    Chrono943::Date tomorrow=today;
    tomorrow.add_day(1);
    std::cout<<"Today: "<<today<<"\n";
    std::cout<<"Tomorrow: "<<tomorrow<<"\n";
    Chrono943::Date invalid_date=Chrono943::Date(2020, 01, -21);
}
