#include "iostream"
#include "vector"

std::vector<int> reverse1(const std::vector<int>& v)
{
	std::vector<int> v_rev(v.size());
	for (int i=0; i<int(v.size()); i++)
		v_rev[i]=v[v.size()-1-i];
	return v_rev;
}

void reverse2(std::vector<int>& v)
{
	for (int i=0; i<int(v.size())/2; ++i)
		std::swap(v[i],v[v.size()-1-i]);
}
void print(const std::string& s, const std::vector<int>& v)
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
		std::vector<int> v1, v2;
		v1.push_back(1);
		v1.push_back(3);
		v1.push_back(5);
		v1.push_back(7);
		v1.push_back(9);
		print("v1    ",v1);
		std::vector<int> v1_rev=reverse1(v1);
		print("v1_rev",v1_rev);
		v2.push_back(0);
		v2.push_back(2);
		v2.push_back(4);
		v2.push_back(6);
		v2.push_back(8);
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
