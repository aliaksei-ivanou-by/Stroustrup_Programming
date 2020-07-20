#include "iostream"

#include "Task_09_11_Chrono.h"

int main()
{
	std::cout<<"Jan 1, 2020 is day #"
			<<Chrono::day_in_year(Chrono::Date(2020, Chrono::Date::jan, 1))<<
			" of the year.\n";
	std::cout<<"Feb 29, 2020 is day #"
			<<Chrono::day_in_year(Chrono::Date(2020, Chrono::Date::feb, 29))<<
			" of the year.\n";
	std::cout<<"Mar 1, 2020 is day #"
			<<Chrono::day_in_year(Chrono::Date(2020, Chrono::Date::mar, 1))<<
			" of the year.\n";
	std::cout<<"Number of leap years since 1970:\n"<<
			"1971: "<<Chrono::n_leapyears(1971)<<"\n"<<
	        "1972: "<<Chrono::n_leapyears(1972)<<"\n"<<
	        "1973: "<<Chrono::n_leapyears(1973)<<"\n"<<
	        "1974: "<<Chrono::n_leapyears(1974)<<"\n"<<
	        "2000: "<<Chrono::n_leapyears(2000)<<"\n"<<
	        "2001: "<<Chrono::n_leapyears(2001)<<"\n"<<
	        "2101: "<<Chrono::n_leapyears(2101)<<"\n";
	std::cout<<"Days since Jan 1, 1970:\n"<<
			"Jan 1, 1970: "<<Chrono::days_linear(Chrono::Date(1970, Chrono::Date::jan, 1))<<"\n"<<
	        "Mar 1, 2001: "<<Chrono::days_linear(Chrono::Date(2001, Chrono::Date::mar, 1))<<"\n"<<
	        "Jan 31, 2014: "<<Chrono::days_linear(Chrono::Date(2014, Chrono::Date::jan, 31))<<"\n"<<
	        "Nov 30, 2111: "<<Chrono::days_linear(Chrono::Date(2111, Chrono::Date::nov, 30))<<"\n";
	std::cout<<"Day of week:\n"<<
			"Jan 1, 1970: "<<Chrono::day_of_week(Chrono::Date(1970, Chrono::Date::jan, 1))<<"\n"<<
			"Sep 11, 2001: "<<Chrono::day_of_week(Chrono::Date(2001, Chrono::Date::sep, 11))<<"\n"<<
			"Jan 24, 2020: "<<Chrono::day_of_week(Chrono::Date(2020, Chrono::Date::jan, 24))<<"\n";
}
