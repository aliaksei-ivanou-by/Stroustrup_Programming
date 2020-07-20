#include "iostream"
#include "fstream"

int main()
try
{
	std::cout<<"Enter input file name: ";
	std::string input;
	std::cin >> input;
	std::ifstream ifs(input.c_str());
	if (!ifs)
		throw "can't open input file\n";
	std::cout<<"Enter output file name: ";
	std::string output;
	std::cin >> output;
	std::ofstream ofs(output.c_str());
	if (!ofs)
		throw "can't open output file\n";

	char ch;
	while(ifs.get(ch))
	{
		if (isalpha(ch))
			ch=tolower(ch);
		ofs<<ch;
	}
}
catch(const char* msg)
{
	std::cout<<msg;
}
