// Простая программа, демонстрирующая работу операторов
#include "iostream"
#include "cmath"
int main()
{
	std::cout<<"Please, enter int number: \n";
	int n;
	std::cin>>n;
	double n_double=n;
	std::cout<<"n == "<<n
			<<"\nn+1 == "<<n+1
			<<"\n3 by n == "<<3*n
			<<"\n2 by n == "<<n+n
			<<"\nsquare of n == "<<n*n
			<<"\nhalf of n == "<<n/2
			<<"\nsqrt of n == "<<sqrt(n_double)
			<<"\nn%2 == "<<n%2
			<<"\n"; // Переход на новую строку
	return 0;
}
