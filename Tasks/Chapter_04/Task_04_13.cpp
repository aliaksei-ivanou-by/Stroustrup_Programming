#include <iostream>
#include "vector"
int main ()
{
	int n=100;
	int a[n+1];
	for (int i=2; i<=n; i++)
	{
		a[i]=i;
	}
	for(int i=2; i<=n; i++)
	{
		if(a[i]!=0)
		{
			std::cout<<a[i]<<" ";
			for(int p=2*i; p<=n; p+=i)
			{
				a[p]=0;
			}
		}
	}
	return 0;
}
