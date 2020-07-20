#include "iostream"
#include "fstream"

bool is_vowel(char ch)
{
    ch=tolower(ch);
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='y';
}

bool all_vowels(const std::string& s)
{
    for (int i=0; i<int(s.size()); ++i)
        if (!is_vowel(s[i]))
        	return false;
    return true;
}

void disemvowels(std::string& s)
{
    std::string s_no_vowels;
    for (int i=0; i<int(s.size()); ++i)
        if (!is_vowel(s[i]))
        	s_no_vowels.push_back(s[i]);
    s=s_no_vowels;
}

int main()
try
{
	//std::cout<<"Enter input file name: ";
	std::string input;
	//std::cin >> input;
	input="Task_11_03_input.txt";
	std::ifstream ifs(input.c_str());
	if (!ifs)
		throw "can't open input file\n";
	//std::cout<<"Enter output file name: ";
	std::string output;
	output="Task_11_03_output.txt";
	//std::cin >> output;
	std::ofstream ofs(output.c_str());
	if (!ofs)
		throw "can't open output file\n";

	char ch;
	std::string s;
	while(ifs.get(ch))
	{
		if (isgraph(ch))
		{
			ifs.unget();
			ifs>>s;
			if (all_vowels(s))
				ifs.get(ch);
			else
			{
				disemvowels(s);
				ofs<<s;
			}
		}
		else
			ofs<<ch;
	}
}
catch(const char* msg)
{
	std::cout<<msg;
}
