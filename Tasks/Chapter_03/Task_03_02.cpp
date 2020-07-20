#include "iostream"
int main()
{
	std::cout<<"Please, enter distance in miles: \n";
	double miles=0;
	std::cin>>miles;
	double km=miles*1609;
	std::cout<<"In "<<miles<<" miles there are "<<km<<" km.\n";
	return 0;
}
