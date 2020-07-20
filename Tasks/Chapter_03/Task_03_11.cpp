#include "iostream"
int main()
{
	std::cout<<"Please, enter the number of one-cent coins : \n";
	int n001=0;
	std::cin>>n001;
	std::cout<<"Please, enter the number of five-cent coins : \n";
	int n005=0;
	std::cin>>n005;
	std::cout<<"Please, enter the number of decimal coins : \n";
	int n010=0;
	std::cin>>n010;
	std::cout<<"Please, enter the number of twenty-five-cent coins : \n";
	int n025=0;
	std::cin>>n025;
	std::cout<<"Please, enter the number of fifty-cent coins : \n";
	int n050=0;
	std::cin>>n050;
	std::cout<<"Please, enter the number of dollar coins : \n";
	int n100=0;
	std::cin>>n100;
	if (n001==1)
		std::cout<<"You have "<<n001<<" one-cent coin.\n";
	else
		if (n001>0)
			std::cout<<"You have "<<n001<<" one-cent coins.\n";
	if (n005==1)
		std::cout<<"You have "<<n005<<" five-cent coin.\n";
	else
		if (n005>0)
			std::cout<<"You have "<<n005<<" five-cent coins.\n";
	if (n010==1)
		std::cout<<"You have "<<n010<<" decimal coin.\n";
	else
		if (n010>0)
			std::cout<<"You have "<<n010<<" decimal coins.\n";
	if (n025==1)
		std::cout<<"You have "<<n025<<" twenty-five-cent coin.\n";
	else
		if (n025>0)
			std::cout<<"You have "<<n025<<" twenty-five-cent coins.\n";
	if (n050==1)
		std::cout<<"You have "<<n050<<" fifty-cent coin.\n";
	else
		if (n050>0)
			std::cout<<"You have "<<n050<<" fifty-cent coins.\n";
	if (n100==1)
		std::cout<<"You have "<<n100<<" dollar coin.\n";
	else
		if (n100>0)
			std::cout<<"You have "<<n100<<" dollar coins.\n";
	int total1=n001+n005*5+n010*10+n025*25+n050*50+n100*100;
	std::cout<<"The total value of your money is "<<total1<<" cents.\n";
	int total21=total1/100;
	int total22=total1%100;
	if ((total21==1)&&(total22==1))
		std::cout<<"The total value of your money is "<<total21<<" dollar and "<<total22<<" cent.\n";
	else
		if ((total21!=1)&&(total22==1))
			std::cout<<"The total value of your money is "<<total21<<" dollars and "<<total22<<" cent.\n";
		else
			std::cout<<"The total value of your money is "<<total21<<" dollars and "<<total22<<" cents.\n";

	return 0;
}
