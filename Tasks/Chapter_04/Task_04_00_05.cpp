#include "iostream"
int square1(int);
int square2(int);
int main()
{
	std::cout<<"Please, enter a number : \n";
	int n=0;
	std::cin>>n;
	int n_sq1=square1(n);
	std::cout<<n_sq1<<" is square of "<<n<<".\n";
	int n_sq2=square2(n);
	std::cout<<n_sq2<<" is square of "<<n<<".\n";
	return 0;
}

int square1(int n)
{
	int n_sq=0;
	for (int i=0;i<n;i++)
		n_sq+=n;
	return n_sq;
}

int square2(int n)
{
	return n*n;
}
