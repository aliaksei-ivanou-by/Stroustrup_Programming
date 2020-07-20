#include "iostream"
#include "vector"

std::vector<std::string> array;

void init()
{
    array.push_back("thousand");
    array.push_back("hundred");
    array.push_back("ten");
    array.push_back("one");
}

int char_to_int(std::vector<int> v)
{
	int num=0;
	try
	{
		if (v.size()==0)
			throw "Empty vector handed to char_to_int()\n";
		if (v.size()>4)
			throw "Char_to_int can handle only up to four digits\n";
		num=0;
		for (int i=0; i<int(v.size()); ++i)
			num=10*num+v[i];
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
	return num;
}

void plural_s(int n)
{
	try
	{
		if (n==0 || n>1)
			std::cout<<'s';
		if (n==1)
			return;
		if (n<0)
			throw "Plural_s can handle only non-negative numbers\n";
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

void print_number(std::vector<int> v, int num)
{
	try
	{
		if (num>9999 || v.size()>4)
			throw "Print_number can only handle numbers with four digits\n";
		if (v.size()==0)
			throw "Print_number was handed an empty vector\n";
		std::cout<<num<<" is ";
		for (int i=0; i<int(v.size()); ++i)
		{
			std::cout<<v[i]<<' '<<array[i+4-v.size()];
			plural_s(v[i]);
			if (i<int(v.size())-1)
				std::cout<<" and ";
		}
		std::cout<<"\n";
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

int main()
{
	try
	{
		init();
		std::cout<<"Enter number with up to four digits, followed by a ';' and a newline.\n";
		std::cout<<"Enter 'q' to exit.\n";
		while (true)
		{
			std::vector<int> ch_vec;
			char ch;
			while (std::cin>>ch)
			{
				if (ch=='q')
					return 0;
				if (ch<'0' || ch>'9')
				{
					std::cin.ignore(10000,'\n');
					break;
				}
				ch_vec.push_back(ch-'0');
			}
			int as_int=char_to_int(ch_vec);
			print_number(ch_vec,as_int);
			std::cout<<"Try again:\n";
		}
		return 0;
	}
	catch (const char* msg)
	{
		std::cout<<msg;
	}
}
