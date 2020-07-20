#include "iostream"
#include "fstream"

int main()
try
{
    std::string s1;
    std::string s2;
    //std::cout<<"Enter first filename: ";
    //std::cin>>s1;
    s1="Task_10_09_file1.txt";
    //std::cout<<"Enter second filename: ";
    //std::cin>>s2;
    s2="Task_10_09_file2.txt";
    std::string output="Task_10_09_output.txt";
    std::ifstream ifs1(s1.c_str());
    if (!ifs1)
    	throw "can't open input file 1\n";
    std::ifstream ifs2(s2.c_str());
    if (!ifs2)
    	throw "can't open input file 2\n";
    std::ofstream ofs(output.c_str());
    if (!ofs)
    	throw "can't open output output file";

    std::string sf1;
    std::string sf2;
    ifs1>>sf1;
    ifs2>>sf2;
    if (sf1=="" || sf2=="")
    	throw "at least one input file is empty\n";

    while(true)
    {
    	if (sf1<=sf2)
    	{
    		std::cout<<sf1<<"\n";
    		ofs<<sf1<<"\n";
    		if (ifs1.eof())
    			break;
    		else
    			ifs1>>sf1;
            }
    	else
    	{
    		std::cout<<sf2<<"\n";
    		ofs<<sf2<<"\n";
    		if (ifs2.eof())
    			break;
    		else
    			ifs2>>sf2;
    	}
    }

}
catch(const char* msg)
{
	std::cout<<msg;
}
