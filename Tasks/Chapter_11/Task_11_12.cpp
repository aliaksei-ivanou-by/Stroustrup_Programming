#include "iostream"
#include "fstream"

int main()
try
{
	std::cout<<"Enter input file: ";
	std::string input;
	std::cin>>input;
	std::ifstream ifs(input.c_str());
	if (!ifs)
		throw "can't open input file";
	std::cout<<"Enter output file: ";
	std::string output;
	std::cin>>output;
	std::ofstream ofs(output.c_str());
	if (!ofs)
		throw "can't open output file";

	std::string temp;
	char ch;
	while (ifs.get(ch))
		temp.push_back(ch);

	for (int i=int(temp.size())-1; i>=0; --i)
		ofs<<temp[i];
}
catch (std::exception& e)
{
    std::cerr<<"exception: "<<e.what()<<"\n";
}
catch (...)
{
    std::cerr<<"exception\n";
}
