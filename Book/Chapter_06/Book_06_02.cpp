#include "iostream"
int main()
{
	try
	{
		std::cout<<"Enter an expression (+, -, * and / allowed): \n";
		std::cout<<"Add x to the end of the expression (1+2*3x) : \n";
		int lval=0;
		int rval;
		std::cin>>lval;
		if (!std::cin)
		{
			throw "No the first operand\n";
		}
		for (char op; std::cin>>op; )
		{
			if (op!='x')
			{
				std::cin>>rval;
			}
			if (!std::cin)
			{
				throw "No the second operand\n";
			}
			switch (op)
			{
			case '+':
				lval+=rval;
				break;
			case '-':
				lval-=rval;
				break;
			case '*':
				lval*=rval;
				break;
			case '/':
				lval/=rval;
				break;
			default:
				std::cout<<"Result : "<<lval<<"\n";
				return 0;
			}
		}
		throw "Wrong expression";
	}

	catch(const char* msg)
	{
		std::cout<<msg;
	}
	return 0;
}
