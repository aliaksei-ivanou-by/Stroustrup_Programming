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

bool contains(const std::string& s, char ch)
{
    for (int i=0; i<int(s.size()); ++i)
        if (s[i]==ch)
        	return true;
    return false;
}


void print_vector(const std::vector<std::string> input)
{
    for (int i=0; i<int(input.size()); ++i)
    	std::cout<<input[i]<<"\n";
}

std::vector<std::string> split(const std::string& input, const std::string& w)
{
    std::string output=input;
    for (int i=0; i<int(output.size()); ++i)
    {
    	for (int j=0; j<w.size(); ++j)
    	{
    		if (contains(w, output[i]))
    			output[i]=' ';
        }
    }
    return split(output);
}

int main()
try
{
	std::cout<<"Enter string with separation characters: ";
	std::string w;
	getline(std::cin, w);
    std::cout<<"Enter: ";
    std::string input;

    while (getline(std::cin, input))
    {
    	std::vector<std::string> output=split(input, w);
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
