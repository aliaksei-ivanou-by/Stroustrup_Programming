#include "iostream"
#include "vector"

std::vector<std::string> reverse1(const std::vector<std::string>& v)
{
	std::vector<std::string> v_rev(v.size());
	for (int i=0; i<int(v.size()); i++)
		v_rev[i]=v[v.size()-1-i];
	return v_rev;
}

void reverse2(std::vector<std::string>& v)
{
	for (int i=0; i<int(v.size())/2; ++i)
		std::swap(v[i],v[v.size()-1-i]);
}
void print(const std::string& s, const std::vector<std::string>& v)
{
	std::cout<<s<<" ("<<int(v.size())<<"): { ";
	for (int i=0; i<int(v.size()); ++i)
	{
		std::cout<<v[i]<<" ";
	}
	std::cout<<"}\n";
}

int main()
{
	try
	{
		std::vector<std::string> v1, v2;
		v1.push_back("aa");
		v1.push_back("bb");
		v1.push_back("cc");
		v1.push_back("dd");
		v1.push_back("ee");
		print("v1    ",v1);
		std::vector<std::string> v1_rev=reverse1(v1);
		print("v1_rev",v1_rev);
		v2.push_back("aaaa");
		v2.push_back("bbbb");
		v2.push_back("cccc");
		v2.push_back("dddd");
		v2.push_back("eeee");
		print("v2",v2);
		reverse2(v2);
		print("v2",v2);
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
	return 0;
}
