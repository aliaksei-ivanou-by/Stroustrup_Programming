#include "iostream"
#include "sstream"
#include "vector"

std::vector<std::string> split(const std::string& input)
{
	std::istringstream is(input);
	std::string temp;
	std::vector<std::string> output;
	while (is>>temp)
		output.push_back(temp);
	return output;
}

void print_vector(const std::vector<std::string> input)
{
    for (int i=0; i<int(input.size()); ++i)
    	std::cout<<input[i]<<"\n";
}

int main()
try
{
    std::cout<<"Enter: ";
    std::string input;

    while (getline(std::cin, input))
    {
    	std::vector<std::string> output=split(input);
    	std::cout<<"\nList:\n";
    	print_vector(output);
    	std::cout<<"\nAgain: ";
    }
}
catch (std::exception& e)
{
    std::cerr<<"exception: "<<e.what()<<"\n";
}
catch (...)
{
    std::cerr<<"exception\n";
}
