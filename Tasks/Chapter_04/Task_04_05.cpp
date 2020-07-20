#include "iostream"
int main()
{
	int key=1;
	while(key)
	{
		std::cout<<"Please, enter 2 double numbers and type of operation : \n";
		double a, b, res;
		std::string c;
		char cc;
		std::cin>>a>>b>>c;
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
				res=a+b;
				std::cout<<"Sum of numbers "<<a<<" and "<<b<<" is ";
				std::cout<<res<<".\n";
				break;
			case '-':
				res=a-b;
				std::cout<<"Difference of numbers "<<a<<" and "<<b<<" is ";
				std::cout<<res<<".\n";
				break;
			case '*':
				res=a*b;
				std::cout<<"Multiplication of numbers "<<a<<" and "<<b<<" is ";
				std::cout<<res<<".\n";
				break;
			case '/':
				res=a/b;
				std::cout<<"Division of numbers "<<a<<" and "<<b<<" is ";
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
