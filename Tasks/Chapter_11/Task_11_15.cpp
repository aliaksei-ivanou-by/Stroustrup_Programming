#include "iostream"
#include "fstream"
#include "vector"
#include "iomanip"

int main()
try
{
	//std::cout<<"Enter input file name: ";
	std::string input;
	//std::cin>>input;
	input="Task_11_15_input.txt";
	std::ifstream ifs(input.c_str());
	if (!ifs)
		throw "can't open input file\n";
	std::string output;
	output="Task_11_15_output.txt";
	//std::cin>>output;
	std::ofstream ofs(output.c_str());
	if (!ofs)
		throw "can't open output file\n";

	double n;
	std::vector<double> numbers;
	while (ifs>>n)
		numbers.push_back(n);

	std::cout<<std::scientific<<std::setprecision(8);
	for (int i=0; i<int(numbers.size()); ++i)
	{
		std::cout<<std::setw(20)<<numbers[i];
		if ((i+1)%4==0)
			std::cout<<"\n";
	}

	ofs<<std::scientific<<std::setprecision(8);
	for (int i=0; i<int(numbers.size()); ++i)
	{
		ofs<<std::setw(20)<<numbers[i];
		if ((i+1)%4==0)
			ofs<<"\n";
	}
}
catch(const char* msg)
{
	std::cout<<msg;
}
