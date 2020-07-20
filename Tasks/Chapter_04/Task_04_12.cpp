#include "iostream"
#include "vector"
bool is_prime_number(int);
int main()
{
	std::vector<int> primes;
	std::cout<<"Please, enter a max for prime numbers : \n";
	int max;
	std::cin>>max;
	for(int i=2; i<max; i++)
	    if (is_prime_number(i)!=0)
	    	primes.push_back(i);
	for (int i : primes)
		std::cout<<i<<" ";
    return 0;
}
bool is_prime_number(int i)
{
	int j;
	for(j=2; j<=(i/j); j++)
	{
		if(!(i%j))
		{
			return false;
		}
		if(j>(i/j))
			return true;
	}
}
