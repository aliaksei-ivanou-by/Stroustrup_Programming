#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"

int main()
{
	double median;
	std::vector<double> num;
	for (double i; std::cin>>i; )
	{
		num.push_back(i);
	}
	std::sort(num.begin(), num.end());
	std::cout<<"Number of numbers = "<<num.size()<<".\n";
	if (num.size()%2==0)
	{
		median=(num[(num.size()-1)/2]+num[num.size()/2])/2;
	}
	else
	{
		median=num[num.size()/2];
	}
	std::cout<<"Median = "<<median<<".\n";
	return 0;
}
