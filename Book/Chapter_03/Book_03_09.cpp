// Небезопасные преобразования
#include "iostream"
int main()
{
	int a=20000;
	char c=a;
	int b=c;
	if (a!=b)
		std::cout<<"?!?: "<<a<<"!="<<b<<"\n";
	else
		std::cout<<"The big char!\n";
	return 0;
}
