#include "iostream"
int main()
{
	int key=1;
	while(key)
	{
		std::cout<<"Please, enter 2 numerals and type of operation : \n";
		std::string a, b;
		double aa, bb, res;
		std::string c;
		char cc;
		std::cin>>a>>b>>c;
		// a
		if (a=="0" || a=="zero")
			aa=0;
		if (a=="1" || a=="one")
			aa=1;
		if (a=="2" || a=="two")
			aa=2;
		if (a=="3" || a=="three")
			aa=3;
		if (a=="4" || a=="four")
			aa=4;
		if (a=="5" || a=="five")
			aa=5;
		if (a=="6" || a=="six")
			aa=6;
		if (a=="7" || a=="seven")
			aa=7;
		if (a=="8" || a=="eight")
			aa=8;
		if (a=="9" || a=="nine")
			aa=9;
		// b
		if (b=="0" || b=="zero")
			bb=0;
		if (b=="1" || b=="one")
			bb=1;
		if (b=="2" || b=="two")
			bb=2;
		if (b=="3" || b=="three")
			bb=3;
		if (b=="4" || b=="four")
			bb=4;
		if (b=="5" || b=="five")
			bb=5;
		if (b=="6" || b=="six")
			bb=6;
		if (b=="7" || b=="seven")
			bb=7;
		if (b=="8" || b=="eight")
			bb=8;
		if (b=="9" || b=="nine")
			bb=9;
		// c
		if (c=="+")
			cc='+';
		else
			if (c=="-")
				cc='-';
			else
				if (c=="*")
					cc='*';
				else
					if (c=="/")
						cc='/';
					else
						cc='?';
		switch(cc)
		{
			case '+':
				res=aa+bb;
				std::cout<<"Sum of numbers "<<aa<<" and "<<bb<<" is ";
				std::cout<<res<<".\n";
				break;
			case '-':
				res=aa-bb;
				std::cout<<"Difference of numbers "<<aa<<" and "<<bb<<" is ";
				std::cout<<res<<".\n";
				break;
			case '*':
				res=aa*bb;
				std::cout<<"Multiplication of numbers "<<aa<<" and "<<bb<<" is ";
				std::cout<<res<<".\n";
				break;
			case '/':
				res=aa/bb;
				std::cout<<"Division of numbers "<<aa<<" and "<<bb<<" is ";
				std::cout<<res<<".\n";
				break;
			default:
				std::cout<<"Sorry, please try again.\n";
				break;
		}
		std::cout<<"Please, enter '1' for entering new numbers or enter '0' to exit : \n";
		std::cin>>key;
	}
	return 0;
}
