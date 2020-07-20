#include "iostream"
int main()
{
	std::cout<<"Please, enter operation and numbers for this operation : \n";
	std::string operation=" ";
	double a=0, b=0;
	std::cin>>operation>>a>>b;
	if ((operation=="+")||(operation=="plus"))
		std::cout<<a<<"+"<<b<<"="<<a+b<<"\n";
	else
		if ((operation=="-")||(operation=="minus"))
			std::cout<<a<<"-"<<b<<"="<<a-b<<"\n";
		else
			if ((operation=="*")||(operation=="mul"))
				std::cout<<a<<"*"<<b<<"="<<a*b<<"\n";
			else
				if ((operation=="/")||(operation=="div"))
					std::cout<<a<<"/"<<b<<"="<<a/b<<"\n";
				else
					std::cout<<"No solution\n";
	return 0;
}
