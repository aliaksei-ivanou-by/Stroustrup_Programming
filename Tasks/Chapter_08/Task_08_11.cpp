#include "iostream"
#include "vector"

void print_until_s(const std::vector<std::string>& v, const std::string& quit)
{
    for (int i=0; i<int(v.size()); ++i)
    {
    	if (v[i]==quit)
    		return;
    	std::cout<<v[i]<<"\n";
    }
}

void print_until_ss(const std::vector<std::string>& v, const std::string& quit)
{
	int key=0;
	for (int i=0; i<int(v.size()); ++i)
	{
		if (v[i]==quit)
			if (key==1)
				return;
			else
				++key;
		std::cout<<v[i]<<"\n";
    }
}

int main()
{
	try
	{
	    std::vector<std::string> v;
	    v.push_back("one");
	    v.push_back("two");
	    v.push_back("three");
	    v.push_back("four");
	    v.push_back("one");
	    v.push_back("two");
	    std::cout<<"print_until_s:\n";
	    print_until_s(v, "two");
	    std::cout<<"print_until_ss:\n";
	    print_until_ss(v, "two");
	    return 0;
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}
