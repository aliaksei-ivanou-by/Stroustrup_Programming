#include "iostream"
#include "vector"
int main()
{
	std::vector<int> arr;
	int n=64;
	int key1=1, key2=1, key3=1;
	constexpr long long int n1=1000, n2=1000000, n3=1000000000;
	// int x=1, sum=0;
	double x=1, sum=0;
	// unsigned long long int  x=1, sum=0;
	for (int i=0;i<n; i++)
	{
		arr.push_back(x);
		sum+=x;
		if ((sum>0))
		{
			std::cout<<i+1<<" : ";
			std::cout<<x<<", sum="<<sum;
			if (key1==1 && sum>n1)
			{
				std::cout<<", sum>"<<n1;
				key1=0;
			}
			if (key2==1 && sum>n2)
			{
				std::cout<<", sum>"<<n2;
				key2=0;
			}
			if (key3==1 && sum>n3)
			{
				std::cout<<", sum>"<<n3;
				key3=0;
			}
			std::cout<<".\n";
			x*=2;
		}
		else
			break;
	}
	return 0;
}
