#include "iostream"
#include "vector"
#include "fstream"

const int not_a_reading=-7777;
const int not_a_month = -1;

struct Day
{
	std::vector<double> hour;
	Day();
};

Day::Day()
		:hour(24)
		 {
			for (int i=0; i<int(hour.size()); ++i)
				hour[i]=not_a_reading;
		 }
struct Month
{
	int month;
	std::vector<Day> day;
	Month()
		:month(not_a_month), day(32) {}
};

struct Year
{
	int year;
	std::vector<Month> month;
	Year()
		:month(12) {}
};

struct Reading
{
	int day;
	int hour;
	double temperature;
};

int month_to_int(std::string s);

bool is_valid(const Reading& r);

void end_of_loop(std::istream& ist, char term, const std::string& message);

std::istream& operator>>(std::istream& is, Reading& r)
try
{
    char ch1;
    if (is>>ch1 && ch1!='(')
    {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }
    char ch2;
    int d;
    int h;
    double t;
    is>>d>>h>>t>>ch2;
    if (!is || ch2!=')')
    	throw "bad reading\n";
    r.day=d;
    r.hour=h;
    r.temperature=t;
    return is;
}
catch(const char* msg)
{
	std::cout<<msg;
}

std::istream& operator>>(std::istream& is, Month& m)
try
{
    char ch=0;
    if (is >> ch && ch!='{')
    {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }
    std::string month_marker;
    std::string mm;
    is>>month_marker>>mm;
    if (!is || month_marker!="month")
    	throw "bad start of month\n";
    m.month=month_to_int(mm);
    Reading r;
    int no_of_duplicate_readings=0;
    int no_invalid_readings=0;
    while (is>>r)
    	if (is_valid(r))
    	{
    		if (m.day[r.day].hour[r.hour]!=not_a_reading)
    			++no_of_duplicate_readings;
    		m.day[r.day].hour[r.hour]=r.temperature;
    	}
    	else
    		++no_invalid_readings;
    end_of_loop(is, '}', "bad end of month");
    return is;
}
catch(const char* msg)
{
	std::cout<<msg;
}

const int implausible_min=-200;
const int implausible_max=200;

bool is_valid(const Reading& r)
{
    if (r.day<1 || 31<r.day)
    	return false;
    if (r.hour<0 || 23<r.hour)
    	return false;
    if (r.temperature<implausible_min || implausible_max<r.temperature)
        return false;
    return true;
}

std::istream& operator>>(std::istream& is, Year& y)
{
    char ch;
    is>>ch;
    if (ch!='{')
    {
        is.unget();
        is.clear(std::ios::failbit);
        return is;
    }
    std::string year_marker;
    int yy;
    is>>year_marker>>yy;
    if (!is || year_marker!="year")
    	throw "bad start of year\n";
    y.year=yy;
    while (true)
    {
        Month m;
        if (!(is>>m))
        	break;
        y.month[m.month]=m;
    }
    end_of_loop(is, '}', "bad end of year");
    return is;
}

void end_of_loop(std::istream& ist, char term, const std::string& message)
{
    if (ist.fail())
    {
        ist.clear();
        char ch;
        if (ist>>ch && ch==term)
        	return;
        throw message;
    }
}

std::vector<std::string> month_input_tbl;

void init_input_tbl(std::vector<std::string>& tbl)
{
    tbl.push_back("jan");
    tbl.push_back("feb");
    tbl.push_back("mar");
    tbl.push_back("apr");
    tbl.push_back("may");
    tbl.push_back("jun");
    tbl.push_back("jul");
    tbl.push_back("aug");
    tbl.push_back("sep");
    tbl.push_back("oct");
    tbl.push_back("nov");
    tbl.push_back("dec");
}

int month_to_int(std::string s)
{
    for (int i=0; i<12; ++i)
    	if (month_input_tbl[i]==s)
    		return i;
    return -1;
}

std::vector<std::string> month_print_tbl;

void init_print_tbl(std::vector<std::string>& tbl)
{
    tbl.push_back("January");
    tbl.push_back("February");
    tbl.push_back("March");
    tbl.push_back("April");
    tbl.push_back("May");
    tbl.push_back("June");
    tbl.push_back("July");
    tbl.push_back("August");
    tbl.push_back("September");
    tbl.push_back("October");
    tbl.push_back("November");
    tbl.push_back("December");
}

std::string int_to_month(int i)
{
    if (i<0 || 12<=i)
    	throw "bad month index\n";
    return month_print_tbl[i];
}

void print_day(std::ostream& ost, const Day& d, int daynum)
{
    bool is_empty=true;
    for (int i=0; i<24; ++i)
    {
        if (d.hour[i]!=not_a_reading)
        {
            is_empty=false;
            break;
        }
    }
    if (is_empty)
    	return;
    ost<<"\n        "<<daynum;
    for (int i=0; i<24; ++i)
    {
        if (d.hour[i]!=not_a_reading)
            ost<<"\n            "<<i<<":00 - "<<d.hour[i]<<" F";
    }
}

void print_month(std::ostream& ost, const Month& m)
{
    if (m.month==not_a_month)
    	return;
    ost<<"\n    "<<int_to_month(m.month);
    for (int i=1; i<32; ++i)
        print_day(ost, m.day[i], i);
}

void print_year(std::ostream& ost, const Year& y)
{
    ost<<y.year<<' ';
    for (int i=0; i<12; ++i)
        print_month(ost, y.month[i]);
}

int main()
try
{
	 init_print_tbl(month_print_tbl);
	 init_input_tbl(month_input_tbl);

	 //std::cout<<"Please enter input file name\n";
	 std::string name;
	 name="Task_10_05_input.txt";
	 //std::cin>>name;
	 std::ifstream ifs(name.c_str());
	 if (!ifs)
		 throw "can't open input file\n";
	 ifs.exceptions(ifs.exceptions()|std::ios_base::badbit);
	 //std::cout<<"Please enter output file name\n";
	 //std::cin>>name;
	 name="Task_10_05_output.txt";
	 std::ofstream ofs(name.c_str());
	 if (!ofs)
		 throw "can't open output file\n";
	 std::vector<Year> ys;
	 while (true)
	 {
		 Year y;
		 if (!(ifs>>y))
			 break;
		 ys.push_back(y);
	 }
     std::cout<<"read "<<ys.size()<<" years of readings\n";
     for (int i=0; i<int(ys.size()); ++i)
     {
    	 print_year(ofs,ys[i]);
    	 ofs<<"\n";
     }
}
catch(const char* msg)
{
	std::cout<<msg;
}
