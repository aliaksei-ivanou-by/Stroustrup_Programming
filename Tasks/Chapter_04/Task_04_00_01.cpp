#include "iostream"
int main()
{
	constexpr double UAH2USD=0.04214096;
	constexpr double RUB2USD=0.01611290;
	constexpr double CNY2USD=0.14356337;
	double value=0;
	char unit=' ';
	std::cout<<"Please, enter the amount and currency to convert to USD ('u' for UAH, 'r' for RUB, 'c' for CNY) : \n";
	std::cin>>value>>unit;
	if (unit=='u')
		std::cout<<value<<" UAH = "<<value*UAH2USD<<" USD.\n";
	else
		if (unit=='r')
			std::cout<<value<<" RUB = "<<value*RUB2USD<<" USD.\n";
		else
			if (unit=='c')
				std::cout<<value<<" CNY = "<<value*CNY2USD<<" USD.\n";
			else
				std::cout<<"Sorry!\n";
	return 0;
}
