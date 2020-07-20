#include "iostream"
int main()
{
	std::cout<<"Please, enter 2 int numbers: \n";
	int val1=0, val2=0;
	std::cin>>val1>>val2;
	if (val1>val2)
	{
		std::cout<<"Max is val1 = "<<val1<<"\n";
		std::cout<<"Min is val2 = "<<val2<<"\n";
	}
	else
	{
		std::cout<<"Max is val2 = "<<val2<<"\n";
		std::cout<<"Min is val1 = "<<val1<<"\n";
	}
	std::cout<<"Sum val1 and val2 = "<<val1+val2<<"\n";
	std::cout<<"Difference val1 and val2 = "<<val1-val2<<"\n";
	std::cout<<"Multiplication val1 and val2 = "<<val1*val2<<"\n";
	std::cout<<"Number division val1 and val2 = "<<val1/val2<<"\n";
	return 0;
}
