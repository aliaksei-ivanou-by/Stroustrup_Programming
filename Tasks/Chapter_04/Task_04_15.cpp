#include "iostream"
#include "vector"
bool is_prime_number(int);
int main()
{
	std::vector<int> primes;
	std::cout<<"Please, enter n : \n";
	int n, key;
	std::cin>>n;
	for(int i=2; ; i++)
	{
		if (is_prime_number(i)!=0)
		{
			primes.push_back(i);
			key++;
		}
		if (key==n)
			break;
	}
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
