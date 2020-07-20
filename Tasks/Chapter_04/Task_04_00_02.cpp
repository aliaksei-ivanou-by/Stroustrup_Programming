#include "iostream"
int main()
{
	constexpr double UAH2USD=0.04214096;
	constexpr double RUB2USD=0.01611290;
	constexpr double CNY2USD=0.14356337;
	constexpr double EUR2USD=1.11707271;
	constexpr double GBP2USD=1.30874964;
	double value=0;
	char unit=' ';
	std::cout<<"Please, enter the amount and currency to convert to USD ('u' for UAH, 'r' for RUB, 'c' for CNY, 'e' for EUR, 'g' for GBP) : \n";
	std::cin>>value>>unit;
	switch (unit)
	{
		case 'u':
			std::cout<<value<<" UAH = "<<value*UAH2USD<<" USD.\n";
			break;
		case 'r':
			std::cout<<value<<" RUB = "<<value*RUB2USD<<" USD.\n";
			break;
		case 'c':
			std::cout<<value<<" CNY = "<<value*CNY2USD<<" USD.\n";
			break;
		case 'e':
			std::cout<<value<<" EUR = "<<value*EUR2USD<<" USD.\n";
			break;
		case 'g':
			std::cout<<value<<" GPR = "<<value*GBP2USD<<" USD.\n";
			break;
		default:
			std::cout<<"\n";
			break;
	}
	return 0;
}
