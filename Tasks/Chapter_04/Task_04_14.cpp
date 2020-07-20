#include <iostream>
#include "vector"
int main ()
{
	int max;
	std::cout<<"Please, enter a max number : \n";
	std::cin>>max;
	int a[max+1];
	for (int i=2; i<=max; i++)
	{
		a[i]=i;
	}
	for(int i=2; i<=max; i++)
	{
		if(a[i]!=0)
		{
			std::cout<<a[i]<<" ";
			for(int p=2*i; p<=max; p+=i)
			{
				a[p]=0;
			}
		}
	}
	return 0;
}
