#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
int main()
{
	std::vector<int> key;
	std::string a;
	std::vector<std::string> arr;
	while(std::cin>>a)
	{
		std::cout<<"str : "<<a<<"\n";
		arr.push_back(a);
		std::cout<<"Array : ";
		for (std::string i : arr)
			std::cout<<i<<" ";
		std::cout<<"\n";
		std::sort(arr.begin(), arr.end());
		std::cout<<"Number of numbers : "<<arr.size()<<"\n";
		std::cout<<"Mode : ";
	std::vector<std::string> arr_mod=arr;
	int n_mod=1;
	std::sort(arr_mod.begin(), arr_mod.end()), std::less<std::string>();
	for (double i=arr_mod.size()-1; i>=0; i--)
	{
		if (arr_mod[i-1]==arr_mod[i])
			n_mod++;
		else
			break;
	}
	std::cout<<" number of modes : "<<n_mod<<", number is : "<<arr_mod[arr_mod.size()-1]<<"\n";
	std::cout<<"Max str : "<<arr_mod[arr_mod.size()-1]<<"\n";
	std::cout<<"Min str : "<<arr_mod[0]<<"\n";
	}
	return 0;
}
