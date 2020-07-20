#include "iostream"
#include "vector"
#include "fstream"

void read_numbers(std::vector<int>& numbers, const std::string& filename)
try
{
	std::ifstream ist(filename.c_str());
	if (!ist)
		throw "can't open input file\n";
	 int n;
	 while (ist>>n)
		 numbers.push_back(n);
}
catch(const char* msg)
{
	std::cout<<msg;
}

int get_sum(std::vector<int>& numbers)
{
	int sum=0;
	for(int i=0; i<int(numbers.size()); i++)
		sum+=numbers[i];
	return sum;
}

int main()
try
{
	std::cout<<"Enter file name: ";
	std::string filename;
	std::cin >> filename;
	std::vector<int> numbers;
	read_numbers(numbers, filename);
	int sum=get_sum(numbers);
	std::cout<<"Sum of numbers in "<<filename<<" is "<<sum<<".\n";
}
catch(const char* msg)
{
	std::cout<<msg;
}
