#include "iostream"
#include "vector"
#include "fstream"
#include "cmath"
#include "algorithm"

struct Reading
{
	int hour;
	double temperature;
	Reading()
		:hour(0), temperature(0) {}
	Reading(int h, double t)
		:hour(h), temperature(t) {}
};

const int max_temp=200;
const int min_temp=-60;

bool operator<(const Reading& r1, const Reading& r2)
{
	return r1.temperature<r2.temperature;
}

std::ostream& operator<<(std::ostream& os, Reading& r)
{
	return os<<r.hour<<' '<<r.temperature;
}

std::istream& operator>>(std::istream& is, Reading& r)
{
	int hour;
	double temperature;
	is>>hour>>temperature;
	if(!is)
		return is;
	r=Reading(hour, temperature);
	return is;
}

void write_from_file(std::vector<Reading>& readings, const std::string& filename)
try
{
    std::ifstream ist(filename.c_str());
    if (!ist)
    	throw "can't open input file\n";
    Reading r;
    while (ist>>r)
    {
        if (r.hour<0 || r.hour>23)
        	throw "hour out of range\n";
        if (r.temperature<min_temp || r.temperature>max_temp)
            throw "temperature out of range\n";
        readings.push_back(r);
    }
}
catch(const char* msg)
{
	std::cout<<msg;
}

int main()
try
{
	std::vector<Reading> readings;
	write_from_file(readings, "Task_10_02_raw_temps.txt");

	sort(readings.begin(), readings.end());
	double temp_median=readings[readings.size()/2].temperature;

	double sum=0;
	for (int i=0; i<readings.size(); ++i)
		sum+=readings[i].temperature;
	double temp_avg=sum/readings.size();

	std::cout<<"Median temperature: "<<temp_median<<" C\n";
	std::cout<<"Average temperature: "<<temp_avg<< " C\n";

}
catch(const char* msg)
{
	std::cout<<msg;
}
