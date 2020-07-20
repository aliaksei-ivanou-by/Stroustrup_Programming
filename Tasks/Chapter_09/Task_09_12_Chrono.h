#include "iostream"

namespace Chrono
{
	class Date
	{
		public:
			enum Month
			{
				jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
			};
			class Invalid {};
			Date(int y, Month m, int d);
			Date();

			int day() const
			{
				return d;
			}
			Month month() const
			{
				return m;
			}
			int year() const
			{
				return y;
			}
			void add_day(int n);
			void add_month(int n);
			void add_year(int n);
		private:
			int y;
			Month m;
			int d;
	};

	bool is_date(int y, Date::Month m, int d);
	bool leapyear(int y);
	int n_leapyears(int y);
	long int days_linear(const Date& d);
	enum Day
	{
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};
	Day day_of_week(const Date& d);
	int day_in_year(const Date& d);
	std::ostream& operator<<(std::ostream& os, Day d);
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);

	std::ostream& operator<<(std::ostream& os, const Date& d);
	std::istream& operator>>(std::istream& is, Date& dd);

	std::ostream& operator<<(std::ostream& os, Day d);
}
