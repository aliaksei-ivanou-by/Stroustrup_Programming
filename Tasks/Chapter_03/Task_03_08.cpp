#include "iostream"
int main()
{
	std::cout<<"Please, enter int number : \n";
	int num=0;
	std::cin>>num;
	if (num%2==0)
		std::cout<<"Number "<<num<<" is even number\n";
	else
		std::cout<<"Number "<<num<<" is odd number\n";
	return 0;
}
