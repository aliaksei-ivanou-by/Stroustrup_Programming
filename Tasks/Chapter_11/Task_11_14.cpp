#include "iostream"
#include "fstream"

int main()
try
{
	//std::cout<<"Enter input file name: ";
	std::string input;
	//std::cin>>input;
	input="Task_11_14_input.txt";
	std::ifstream ifs(input.c_str());
	if (!ifs)
		throw "can't open input file\n";

	char ch;
	int space=0;
	int alpha=0;
	int digit=0;
	int xdigit=0;
	int upper=0;
	int lower=0;
	int alnum=0;
	int cntrl=0;
	int punct=0;
	int print=0;
	int graph=0;

	while(ifs.get(ch))
	{
		if (isspace(ch))
			space++;
		if (isalpha(ch))
			alpha++;
		if (isdigit(ch))
			digit++;
		if (isxdigit(ch))
			xdigit++;
		if (isupper(ch))
			upper++;
		if (islower(ch))
			lower++;
		if (isalnum(ch))
			alnum++;
		if (iscntrl(ch))
			cntrl++;
		if (ispunct(ch))
			punct++;
		if (isprint(ch))
			print++;
		if (isgraph(ch))
			graph++;
	}

	std::cout<<"Results :\n";
	std::cout<<"space:\t"<<space<<"\n";
	std::cout<<"alpha:\t"<<alpha<<"\n";
	std::cout<<"digit:\t"<<digit<<"\n";
	std::cout<<"xdigit:\t"<<xdigit<<"\n";
	std::cout<<"upper:\t"<<upper<<"\n";
	std::cout<<"lower:\t"<<lower<<"\n";
	std::cout<<"alnum:\t"<<alnum<<"\n";
	std::cout<<"cntrl:\t"<<cntrl<<"\n";
	std::cout<<"punct:\t"<<punct<<"\n";
	std::cout<<"print:\t"<<print<<"\n";
	std::cout<<"graph:\t"<<graph<<"\n";
}
catch(const char* msg)
{
	std::cout<<msg;
}
