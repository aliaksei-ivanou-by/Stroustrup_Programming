#include "iostream"
int main()
{
	std::cout<<"Enter an expression (+ and - allowed): \n";
	int lval=0;
	int rval;
	char op;
	int res;
	std::cin>>lval>>op>>rval;
	if (op=='+')
		res=rval+lval;
	else
		if (op=='-')
			res=rval-lval;
	std::cout<<"Result : "<<res<<"\n";
	return 0;
}
