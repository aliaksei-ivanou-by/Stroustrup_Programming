#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"

int main()
{
	std::vector<double> arr;
	for (double i; std::cin>>i; )
	{
		arr.push_back(i);
	}
    std::sort(arr.begin(), arr.end());
    std::cout<<"Min of array is : "<<arr[0]<<".\n";
    std::cout<<"Max of array is : "<<arr[arr.size()-1]<<".\n";
    std::cout<<"Number of numbers is : "<<arr.size()<<".\n";
    double sum=0;
    for (double i : arr)
    {
    	sum+=i;
    }
    std::cout<<"Sum of array : "<<sum<<".\n";
    std::cout<<"Mean distance is : "<<sum/arr.size()<<".\n";
	return 0;
}
