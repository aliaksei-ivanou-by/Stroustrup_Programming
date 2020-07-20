#include "iostream"
#include "vector"
#include "fstream"

struct Reading
{
	int hour;
	double temperature;
	Reading(int h, double t)
		:hour(h), temperature(t) {}
};

const int max_temp=200;
const int min_temp=-60;

std::ostream& operator<<(std::ostream& os, const Reading& r)
{
	return os<<r.hour<<' '<<r.temperature;
}

Reading create_reading()
{
	int h=rand()%24+0;
    double t=rand()%max_temp+min_temp+(rand()%10)/double(10);
    if (t>max_temp || t<min_temp)
    	std::cout<<t<<"\n";
    return Reading(h, t);
}

void write_to_file(const std::vector<Reading>& r, const std::string& filename)
try
{
    std::ofstream ost(filename.c_str());
    if (!ost)
    	throw "can't open output file\n";
    for (int i=0; i<int(r.size()); ++i)
    	ost<<r[i]<<"\n";
}
catch(const char* msg)
{
	std::cout<<msg;
}

int main()
try
{
	std::vector<Reading> readings;
	for (int i=0; i<250; ++i)
		readings.push_back(create_reading());
	write_to_file(readings, "Task_10_02_raw_temps.txt");
}
catch(const char* msg)
{
	std::cout<<msg;
}
