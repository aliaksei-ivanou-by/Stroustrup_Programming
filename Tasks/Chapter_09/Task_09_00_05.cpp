#include "iostream"
#include "Task_09_00_05_Chrono.h"

int main()
{
    std::cout<<"Chapter 9.7.4:\n";
    Chrono974::Date default_date;
    std::cout<<"Default date: "<<default_date<<"\n";
    Chrono974::Date today(1963, Chrono974::Date::may, 19);
    Chrono974::Date tomorrow=today;
    tomorrow.add_day(1);
    Chrono974::Date next_year=today;
    next_year.add_year(1);
    std::cout<<"Today: "<<today<<"\n";
    std::cout<<"Tomorrow: "<<tomorrow<<"\n";
    std::cout<<"Next year: "<<next_year<<"\n";
    Chrono974::Date invalid_date=Chrono974::Date(2020, Chrono974::Date::jan, -21);
}
