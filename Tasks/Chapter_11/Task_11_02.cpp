#include "iostream"
#include "fstream"

int main()
try
{
	//std::cout<<"Enter input file name: ";
	std::string input;
	//std::cin>>input;
	input="Task_11_02.cpp";
	std::ifstream ifs(input.c_str());
	//std::cout<<"Enter word match: ";
	std::string word_match;
	//std::cin>>word_match;
	word_match="cout";
	std::string line;
	for(size_t line_number=1; std::getline(ifs, line); ++line_number)
	{
		if(std::string::npos!=line.find(word_match))
		{
			std::cout<<line_number<<line<<"\n";
		}
	}
}
catch(const char* msg)
{
	std::cout<<msg;
}
