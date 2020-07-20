#include "iostream"
#include "iomanip"

int main()
{
	std::cout<<"Enter space-separated integers in decimal, octal or hexadecimal notation\n"<<
			"(using 0 and 0x prefixes), any letter to finish:\n";
	int n=0;
	char ch;
	while (std::cin>>ch)
	{
		if(ch=='0')
		{
			std::cin.get(ch);
			if (ch=='x') // hex
			{
				std::cin>>std::hex>>n;
				std::cout<<std::hex<<n<<" (hex) ";
				std::cout<<"converts to "<<std::dec<<n<<" (dec).\n";
			}
			else
				if (isdigit(ch)) // oct
				{
					std::cin.unget();
					std::cin>>std::oct>>n;
					std::cout<<std::oct<<n<<" (oct) ";
					std::cout<<"converts to "<<std::dec<<n<<" (dec).\n";
				}
		}
		else
		{
			if (isdigit(ch)) // dec
			{
				std::cin.unget();
				std::cin>>std::dec>>n;
				std::cout<<std::dec<<n<<" (dec) ";
				std::cout<<"converts to "<<std::dec<<n<<" (dec).\n";
			}
			else
				break;
		}
	}
	return 0;
}
