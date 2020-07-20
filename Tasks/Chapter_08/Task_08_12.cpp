#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"

void print(const std::vector<int>& input)
{
	std::cout<<"{ ";
	for (int i=0; i<int(input.size()); ++i)
		std::cout<<input[i]<<" ";
	std::cout<<" }\n";
}

void print(const std::vector<std::string>& input)
{
	std::cout<<"{ ";
	for (int i=0; i<int(input.size()); ++i)
		std::cout<<input[i]<<" ";
	std::cout<<" }\n";
}

std::vector<int> string_lengths(std::vector<std::string> input)
{
	try
	{
		if (input.size()==0)
			throw "string_lengths: argument is empty vector\n";
		std::vector<int> output;
		for (int i=0; i<int(input.size()); ++i)
			output.push_back(input[i].size());
		return output;
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

std::string string_min(const std::vector<std::string>& input)
{
	try
	{
		if (input.size() == 0)
			throw "string_min: argument is empty vector";
		std::string output=input[0];
		int min=input[0].size();
		for (int i=1; i<int(input.size()); ++i)
		{
			if (input[i].size()<min)
			{
				min=input[i].size();
				output=input[i];
			}
		}
		return output;
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

std::string string_max(const std::vector<std::string>& input)
{
	try
	{
		if (input.size()==0)
			throw "string_max: argument is empty vector";
		std::string output;
		int max=0;
		for (int i=0; i<int(input.size()); ++i)
		{
			if (input[i].size()>max)
			{
				max=input[i].size();
				output=input[i];
			}
		}
	    return output;
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

std::string string_lexis_first(const std::vector<std::string>& input)
{
	try
	{
		if (input.size()==0)
			throw "string_lexis_first: argument is empty vector";
		std::vector<std::string> output=input;
		sort(output.begin(), output.end());
		return output[0];
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

std::string string_lexis_last(const std::vector<std::string>& input)
{
	try
	{
		if (input.size()== 0)
			throw "string_lexis_last: argument is empty vector";
		std::vector<std::string> output=input;
		std::sort(output.begin(), output.end()), std::greater<std::string>();
		return output[output.size()-1];
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

int main()
{
	try
	{
		std::vector<std::string> v;
		v.push_back("first");
		v.push_back("second");
		v.push_back("third");
		v.push_back("fourth");
		v.push_back("fifth");
		v.push_back("sixth");
		v.push_back("seventh");
		std::cout<<"Vector of v:\n";
		print(v);
		std::vector<int> lengths=string_lengths(v);
		std::cout<<"Vector of lengths:\n";
		print(lengths);
		std::cout<<"Max string : "<<string_max(v)<<"\n";
		std::cout<<"Shortest string : "<<string_min(v)<< "\n";
		std::cout<<"Lexicographically first string : "<<string_lexis_first(v)<<"\n";
		std::cout<<"Lexicographically last string : "<<string_lexis_last(v)<<"\n";
		return 0;
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}
