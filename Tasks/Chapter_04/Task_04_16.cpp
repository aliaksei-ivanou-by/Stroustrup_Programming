#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
int main()
{
	std::vector<int> key;
	double a;
	std::vector<double> arr;
	while(std::cin>>a)
	{
		std::cout<<"Number : "<<a<<"\n";
		arr.push_back(a);
		std::cout<<"Array : ";
		for (int i : arr)
			std::cout<<i<<" ";
		std::cout<<"\n";
		std::sort(arr.begin(), arr.end());
		std::cout<<"Number of numbers : "<<arr.size()<<"\n";
		std::cout<<"Mode : ";
	std::vector<double> arr_mod=arr;
	int n_mod=1;
	std::sort(arr_mod.begin(), arr_mod.end(), std::greater<int>());
	for (double i=1; i<arr_mod.size(); i++)
	{
		if (arr_mod[i]==arr_mod[i-1])
			n_mod++;
		else
			break;
	}
	std::cout<<" number of modes : "<<n_mod<<" number is : "<<arr_mod[0]<<"\n";
	}
	return 0;
}
