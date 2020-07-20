#include "iostream"
#include "vector"

void print(const std::string& s, const std::vector<int>& v)
{
    std::cout<<s<<"("<<v.size()<<"): {";
    for (int i=0; i<int(v.size()); ++i)
    {
    	std::cout<<v[i];
    	if (i<int(v.size())-1)
    		std::cout << ", ";
    }
    std::cout<<"}\n";
}

int main()
{
	try
	{
		std::vector<int> v={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		std::string s="Sequence";
		print(s, v);
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}
