#include "iostream"
#include "vector"
int main()
{
	std::vector<double> temps;
	for (double temp; std::cin>>temp; )
		temps.push_back(temp);
	double sum=0;
	double high_temp=0;
	double low_temp=0;
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
	std::cout<<"Mean temp = "<<sum/temps.size()<<"\n";
	return 0;
}
