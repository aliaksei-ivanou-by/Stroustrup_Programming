#include "iostream"
#include "vector"
int main()
{
	std::vector<std::string> num={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	std::cout<<"Please, enter a numeral : \n";
	std::string input="";
	std::cin>>input;
	if (input=="0")
	{
		std::cout<<num[0];
	}
	else if (input=="1")
	{
		std::cout<<num[1];
	}
	else if (input=="2")
	{
		std::cout<<num[2];
	}
	else if (input=="3")
	{
		std::cout<<num[3];
	}
	else if (input=="4")
	{
		std::cout<<num[4];
	}
	else if (input=="5")
	{
		std::cout<<num[5];
	}
	else if (input=="6")
	{
		std::cout<<num[6];
	}
	else if (input=="7")
	{
		std::cout<<num[7];
	}
	else if (input=="8")
	{
		std::cout<<num[8];
	}
	else if (input=="9")
	{
		std::cout<<num[9];
	}
	else if (input=="zero")
	{
		std::cout<<0;
	}
	else if (input=="one")
	{
		std::cout<<1;
	}
	else if (input=="two")
	{
		std::cout<<2;
	}
	else if (input=="three")
	{
		std::cout<<3;
	}
	else if (input=="four")
	{
		std::cout<<4;
	}
	else if (input=="five")
	{
		std::cout<<5;
	}
	else if (input=="six")
	{
		std::cout<<6;
	}
	else if (input=="seven")
	{
		std::cout<<7;
	}
	else if (input=="eight")
	{
		std::cout<<8;
	}
	else if (input=="nine")
	{
		std::cout<<9;
	}
	return 0;
}
