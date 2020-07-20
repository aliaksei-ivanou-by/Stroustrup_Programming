#include "iostream"
#include "fstream"

template<class T>
char* as_bytes(T&i)
{
	void* addr=&i;
	return static_cast<char*>(addr);
}

void convert_to_binary(const std::string& input, const std::string& output_bin)
try
{
    std::ifstream ifs(input.c_str());
    if (!ifs)
    	throw "can't open input txt file";
    std::ofstream ofs(output_bin.c_str(), std::ios_base::binary);
    if (!ofs)
    	throw "can't open output bin file";

    char ch;
    while (ifs.get(ch))
    {
        ofs.write(as_bytes(ch), sizeof(char));
    }
}
catch(const char* msg)
{
	std::cout<<msg;
}

void convert_from_binary(const std::string& input, const std::string& output)
try
{
    std::ofstream ofs(output.c_str());
    if (!ofs)
    	throw "can't open output txt file";
    std::ifstream ifs(input.c_str(), std::ios_base::binary);
    if (!ifs)
    	throw "can't open input bin file";

    char ch;
    while (ifs.read(as_bytes(ch), sizeof(char)))
    {
        ofs<<ch;
    }
}
catch(const char* msg)
{
	std::cout<<msg;
}


int main()
try
{
	std::cout<<"Enter input file txt: ";
	std::string input_txt;
	std::cin>>input_txt;

	std::cout<<"Enter output file bin: ";
	std::string output_bin;
	std::cin>>output_bin;

	convert_to_binary(input_txt, output_bin);

	std::cout<<"Enter output file txt: ";
	std::string output_txt;
	std::cin>>output_txt;

	convert_from_binary(output_bin, output_txt);
}
catch (std::exception& e)
{
    std::cerr<<"exception: "<<e.what()<<"\n";
}
catch (...)
{
    std::cerr<<"exception\n";
}
