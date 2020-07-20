#include "iostream"
#include "vector"
#include "fstream"
#include "algorithm"

int main()
try
{
	//std::cout<<"Enter input file name: ";
	std::string input;
	//std::cin>>input;
	input="Task_11_16_input.txt";
	std::ifstream ifs(input.c_str());
	if (!ifs)
		throw "can't open input file\n";

	int n;
	std::vector<int> numbers;
	while (ifs>>n)
		numbers.push_back(n);

	sort(numbers.begin(), numbers.end());

	int count=1;
	for (int i=0; i<int(numbers.size()); ++i)
	{
		if (i==0 || numbers[i]!=numbers[i-1])
		{
			if (count>1)
				std::cout<<"\t"<<count;
			std::cout<<"\n";
			count=1;
			std::cout<<numbers[i];
		}
		else
			count++;
	}
}
catch(const char* msg)
{
	std::cout<<msg;
}

