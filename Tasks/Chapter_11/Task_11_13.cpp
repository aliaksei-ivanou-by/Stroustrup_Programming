#include "iostream"
#include "fstream"
#include "vector"

int main()
try
{
	//std::cout<<"Enter input file name: ";
	std::string input;
	//std::cin>>input;
	input="Task_11_13_input.txt";
	std::ifstream ifs(input.c_str());
	if (!ifs)
		throw "can't open input file\n";
	//std::cout<<"Enter output file name: ";
	std::string output;
	output="Task_11_13_output.txt";
	//std::cin>>output;
	std::ofstream ofs(output.c_str());
	if (!ofs)
		throw "can't open output file\n";

	std::vector<std::string> text;
	std::string s;
	while (ifs>>s)
		text.push_back(s);
    for (int i=text.size()-1; i>=0; --i)
        ofs<<text[i]<<" ";
}
catch(const char* msg)
{
	std::cout<<msg;
}
