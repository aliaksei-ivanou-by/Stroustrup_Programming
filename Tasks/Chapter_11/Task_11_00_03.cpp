#include "iostream"

int main()
{
	std::cout<<std::defaultfloat;
	std::cout<<"defaultfloat : "<<1234567.89<<"\n";
	std::cout<<std::fixed;
	std::cout<<"fixed : "<<1234567.89<<"\n";
	std::cout<<std::scientific;
	std::cout<<"scientific : "<<1234567.89<<"\n";
	return 0;
}
