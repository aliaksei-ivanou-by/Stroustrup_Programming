#include "iostream"
#include "vector"
int main()
{
	std::cout<<"Please, enter a n for sum : \n";
	int n;
	std::cin>>n;
	int sum=0;
	std::cout<<"Please, enter array of numbers : \n";
	std::cin.exceptions(std::istream::failbit | std::istream::badbit);
	std::vector<int> arr;
	int k=0;
	try
	{
		for(int i; std::cin>>i; )
		{
			arr.push_back(i);
			k++;
		}
	}
	catch(...)
	{
		std::cout<<"Array : \n";
		for(int i : arr)
		{
			std::cout<<i<<" ";
		}
	}
	std::cout<<"\nArr size : "<<arr.size()<<"\n";
	std::cout<<"\n";
	try
	{
		for(int i=0; i<n; i++)
		{

			if (n>arr.size())
				throw "Out of range\n";
			else
				sum+=arr[i];
		}
		std::cout<<"Sum is : "<<sum;
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}

	return 0;
}
