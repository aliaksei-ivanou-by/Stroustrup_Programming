#include "Task_09_12_Chrono.h"

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
		d+=n;
		if (d>31)
			throw "add_day() results in invalid date";
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
		return (y%4==0 && y%100!=0) || y%400==0;
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
	const Date first_date=Date(1970, Date::jan, 1);
	const Day first_day=thursday; // Jan 1, 1970 - Thursday
	int n_leapyears(int y)
	{
		int nl=0;
		for (int i=1970; i<y; ++i)
			if (leapyear(i))
				++nl;
		return nl;
	}
	int nmonth(Date::Month m)
	{
		switch (m)
		{
		case Date::jan:
			return 0;
		case Date::feb:
			return 31;
		case Date::mar:
			return 31+28;
	    case Date::apr:
	    	 31+28+31;
	    case Date::may:
	    	return 31+28+31+30;
	    case Date::jun:
	    	return 31+28+31+30+31;
	    case Date::jul:
	    	return 31+28+31+30+31+30;
	    case Date::aug:
	    	return 31+28+31+30+31+30+31;
	    case Date::sep:
	    	return 31+28+31+30+31+30+31+31;
	    case Date::oct:
	    	return 31+28+31+30+31+30+31+31+30;
	    case Date::nov:
	    	return 31+28+31+30+31+30+31+31+30+31;
	    case Date::dec:
	    	return 31+28+31+30+31+30+31+31+30+31+30;
		}
	}
	int day_in_year(const Date& d)
	{
		int diy=nmonth(d.month());
		diy+=d.day();
		if (leapyear(d.year()) && d.month()>Date::feb)
			++diy;
		return diy;
	}
	long int days_linear(const Date& d)
	{
		if (d.year()<first_date.year())
			throw "days_linear: year must be 1970 or later";
		int y=d.year()-first_date.year();
		return y*365+n_leapyears(d.year())+day_in_year(d)-1;
	}
	Day day_of_week(const Date& d)
	{
		if (d.year()<first_date.year())
			throw "day_of_week: works only for 1970 and later";
		int dlin=days_linear(d);
		return Day((first_day+dlin)%7);
	}
	Date next_Sunday(const Date& d)
	{
		Date nsd=d;
		Day day=day_of_week(d);
		nsd.add_day(7-day);
		return nsd;
	}
	Date next_weekday(const Date& d)
    {
		Date nwd=d;
		Day day=day_of_week(d);
		switch (day)
		{
		case sunday: case monday: case tuesday: case wednesday: case thursday:
			nwd.add_day(1);
			break;
		case saturday:
			nwd.add_day(2);
			break;
		case friday:
			nwd.add_day(3);
			break;
		}
		return nwd;
    }
	std::ostream& operator<<(std::ostream& os, Day d)
	{
		switch (d)
		{
		case sunday:
			os<<"Sunday";
	        break;
	    case monday:
	    	os<<"Monday";
	        break;
	    case tuesday:
	        os<<"Tuesday";
	        break;
	    case wednesday:
	        os<<"Wednesday";
	        break;
	    case thursday:
	        os<<"Thursday";
	        break;
	    case friday:
	        os<<"Friday";
	        break;
	    case saturday:
	        os<<"Saturday";
	        break;
	    }
		return os;
	}
}
