// Простая программа, демонстрирующая работу операторов
#include "iostream"
#include "cmath"
int main()
{
	std::cout<<"Please, enter double number: \n";
	double n;
	std::cin>>n;
	std::cout<<"n == "<<n
			<<"\nn+1 == "<<n+1
			<<"\n3 by n == "<<3*n
			<<"\n2 by n == "<<n+n
			<<"\nsquare of n == "<<n*n
			<<"\nhalf of n == "<<n/2
			<<"\nsqrt of n == "<<sqrt(n)
			<<"\n"; // Переход на новую строку
	return 0;
}
