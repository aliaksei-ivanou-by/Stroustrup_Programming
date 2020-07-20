#include "iostream"
#include "fstream"

int main()
try
{
    std::string s1;
    std::string s2;
    std::cout<<"Enter first filename: ";
    std::cin>>s1;
    std::cout<<"Enter second filename: ";
    std::cin>>s2;
    std::string output="Task_10_08_output.txt";
    std::ifstream ifs1(s1.c_str());
    if (!ifs1)
    	throw "can't open input file 1\n";
    std::ifstream ifs2(s2.c_str());
    if (!ifs2)
    	throw "can't open input file 2\n";
    std::ofstream ofs(output.c_str());
    if (!ofs)
    	throw "can't open output output file";
    char ch;
    while (ifs1.get(ch))
    	ofs<<ch;
    while (ifs2.get(ch))
    	ofs<<ch;
}
catch(const char* msg)
{
	std::cout<<msg;
}
