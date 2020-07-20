#include "iostream"

void char_class(const std::string& s)
{
	for (int i=0; i<int(s.size()); i++)
	{
		std::cout<<s[i];
		if (isspace(s[i]))
			std::cout<<" isspace";
		if (isalpha(s[i]))
			std::cout<<" isalpha";
		if (isdigit(s[i]))
			std::cout<<" isdigit";
		if (isxdigit(s[i]))
			std::cout<<" isxdigit";
		if (isupper(s[i]))
			std::cout<<" isupper";
		if (islower(s[i]))
			std::cout<<" islower";
		if (isalnum(s[i]))
			std::cout<<" isalnum";
		if (iscntrl(s[i]))
			std::cout<<" iscntrl";
		if (ispunct(s[i]))
			std::cout<<" ispunct";
		if (isprint(s[i]))
			std::cout<<" isprint";
		if (isgraph(s[i]))
			std::cout<<" isgraph";
		std::cout<<"\n";
	}
}

int main()
{
	std::cout<<"Enter line:\n";
	std::string s;
	while (std::cin>>s)
	{
		char_class(s);
		std::cout<<"\n";
	}
	return 0;
}
