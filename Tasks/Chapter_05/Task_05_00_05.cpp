#include "iostream"
#include "vector"
int main()
{
	std::vector<double> temps;
	double sum=0;
	double high_temp=-460;
	double low_temp=2000000;
	int no_of_temps=0;
	for (double temp; std::cin>>temp; )
	{
		++no_of_temps;
		sum+=temp;
		temps.push_back(temp);
	}
	for (int x : temps)
	{
		if (x>high_temp)
			high_temp=x;
		if (x<low_temp)
			low_temp=x;
		sum+=x;
	}
	std::cout<<"Max temp = "<<high_temp<<"\n";
	std::cout<<"Min temp = "<<low_temp<<"\n";
	std::cout<<"Mean temp = "<<sum/no_of_temps<<"\n";
	return 0;
}
