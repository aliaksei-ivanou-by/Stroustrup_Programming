#include "Task_09_00_03_Chrono.h"

namespace Chrono
{
	Date::Date(int yy, Month mm, int dd)
		: y(yy), m(mm), d(dd)
	{
		if (!is_date(yy,mm,dd))
			throw Invalid();
	}
	const Date& default_date()
	{
		static const Date dd(2001, Date::jan, 1);
		return dd;
	}
	Date::Date()
		:y(default_date().year()),
		 m(default_date().month()),
		 d(default_date().day())
	{}
	void Date::add_day(int n)
	{
		// ...
	}
	void Date::add_month(int n)
	{
		// ...
	}
	void Date::add_year(int n)
	{
		if (m==feb && d==29 && !leapyear(y+n))
		{
			m=mar;
			d=1;
		}
		y+=n;
	}
	bool is_date(int y, Date::Month m, int d)
	{
		if (d<=0)
			return false;
		int days_in_month=31;
		switch (int(m))
		{
		case Date::feb:
			days_in_month=(leapyear(y))?29:28;
			break;
		case Date::apr: case Date::jun: case Date::sep: case Date::nov:
			days_in_month=30;
			break;
		}
		if (days_in_month<d)
			return false;
		return true;
    }
	bool leapyear(int y)
	{
		return true;
	}
	bool operator==(const Date& a, const Date& b)
	{
		return a.year()==b.year()
				&& a.month()==b.month()
				&& a.day()==b.day();
	}
	bool operator!=(const Date& a, const Date& b)
	{
		return !(a==b);
	}
	std::ostream& operator<<(std::ostream& os, const Date& d)
	{
		return os<<'('<<d.year()
				<<','<<d.month()
				<<','<<d.day()<<')';
	}
	std::istream& operator>>(std::istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is>>ch1>>y>>ch2>>m>>ch3>>d>>ch4;
		if (!is)
			return is;
		if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')')
		{
			is.clear(std::ios_base::failbit);
			return is;
		}
		dd=Date(y,Date::Month(m),d);
		return is;
	}
	Day day_of_week(const Date& d)
	{
		// ...
	}
	Date next_Sunday(const Date& d)
	{
		// ...
	}
	Date next_weekday(const Date& d)
    {
       // ...
    }
}

namespace Chrono941
{
	void init_day(Date& dd, int y, int m, int d)
	{
		if (m<1 || m>12 || d<1 || d>31)
			throw "invalid date\n";
		dd.y=y;
		dd.m=m;
		dd.d=d;
	}
	void add_day(Date& dd, int n)
	{
		init_day(dd,dd.y, dd.m,dd. d+n);
	}
	std::ostream& operator<<(std::ostream& os, const Date& d)
	{
		return os<<'('<<d.y<<','<<d.m<<','<<d.d<<')';
	}
}

namespace Chrono942
{
	Date::Date(int y, int m, int d)
		:y(y), m(m), d(d)
	{
		if (m<1 || m>12 || d<1 || d>31)
			throw "invalid date";
	}
	void Date::add_day(int n)
	{
		d+=n;
		if (d>31)
			throw "add_day() results in invalid date";
	}
	std::ostream& operator<<(std::ostream& os, const Date& d)
	{
		return os<<'('<<d.y<<','<<d.m<<','<<d.d<<')';
	}
}

namespace Chrono943
{
	Date::Date(int yy, int mm, int dd)
		:y(yy), m(mm), d(dd)
	{
		if (m<1 || m>12 || d<1 || d>31)
			throw("invalid date");
	}
	void Date::add_day(int n)
	{
		d+=n;
		if (d>31)
			throw "add_day() results in invalid date";
    }

    std::ostream& operator<<(std::ostream& os, Date& d)
    {
    	return os<<'('<<d.year()<<','<<d.month()<<','<<d.day()<<')';
    }
}
