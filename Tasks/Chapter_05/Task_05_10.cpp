#include "iostream"
#include "vector"
int main()
{
	std::cout<<"Please, enter a n for sum : \n";
	int n;
	std::cin>>n;
	double sum=0;
	std::cout<<"Please, enter array of numbers : \n";
	std::cin.exceptions(std::istream::failbit | std::istream::badbit);
	std::vector<double> arr, arr_dif;
	int k=0;
	try
	{
		for(double i; std::cin>>i; )
		{
			arr.push_back(i);
			k++;
		}
	}
	catch(...)
	{
		std::cout<<"Last number is not a double number!\n";
		std::cout<<"Array : \n";
		for(double i : arr)
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
		for(int i=0; i<n-1; i++)
		{
			double arr_dif_i=arr[i+1]-arr[i];
			arr_dif.push_back(arr_dif_i);
		}
		std::cout<<"\nDif : \n";
		for(double ii : arr_dif)
			std::cout<<ii<<" ";
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}

	return 0;
}
