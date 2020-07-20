#include "iostream"
#include "vector"
int main()
{
	try
	{
		std::vector<int> arr;
		int sum=0;
		arr.push_back(1);
		std::cout<<1<<" "<<arr[0]<<" \n";
		arr.push_back(1);
		std::cout<<2<<" "<<arr[1]<<" \n";
		for (int i=2; ; i++)
		{
			sum=arr[i-1]+arr[i-2];
			if (sum<0)
				throw "\nOut of range\n";
			arr.push_back(sum);
			std::cout<<i<<" "<<arr[i]<<" \n";
		}
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
	return 0;
}
