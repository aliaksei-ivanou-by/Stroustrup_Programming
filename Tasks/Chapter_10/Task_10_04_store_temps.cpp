#include "iostream"
#include "vector"
#include "fstream"

const char scale_F='F';
const char scale_C='C';
const int max_temp=200;
const int min_temp=-60;

struct Reading
{
	int hour;
	double temperature;
	char scale;
	Reading(int h, double t, char sc)
		:hour(h), temperature(t), scale(sc) {}
};

std::ostream& operator<<(std::ostream& os, const Reading& r)
{
	return os<<r.hour<<' '<<r.temperature<<r.scale;
}

Reading create_reading()
{
	int h=rand()%24+0;
    double t=rand()%max_temp+min_temp+(rand()%10)/double(10);
    char sc;
    int key=rand()%1;
    if (key==1)
    	sc=scale_F;
    else
    	sc=scale_C;
    return Reading(h, t, sc);
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
	write_to_file(readings, "Task_10_04_raw_temps.txt");
}
catch(const char* msg)
{
	std::cout<<msg;
}
