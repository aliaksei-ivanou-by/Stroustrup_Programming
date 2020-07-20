#include "iostream"
#include "vector"
#include "cmath"
#include "algorithm"

std::vector<std::string> name;
std::vector<double> age;

void enter_names()
{
	std::string s;
	std::cout<<"Enter names : \n";
	while(std::cin>>s && s!="done")
	{
		for (int i=0; i<int(name.size()); i++)
			if (s==name[i])
			{
				throw "Duplicate name";
			}
		name.push_back(s);
	}
	for (int i=0; i<int(name.size()); i++)
	{
		std::cout<<"Age of "<<name[i]<<" : ";
		double a;
		std::cin>>a;
		age.push_back(a);
	}
}

void print(const std::vector<std::string>& name, const std::vector<double>& age)
{
	try
	{
		if (name.size()!=age.size())
			throw "print(): vectors must be same size";
		for (int i=0; i<int(name.size()); i++)
			std::cout<<"("<<name[i]<<", "<<age[i]<<")\n";
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

int find_index(const std::vector<std::string>& v, const std::string& s)
{
	try
	{
		for (int i=0; i<int(v.size()); ++i)
		{
			if (v[i]==s)
				return i;
		}
    throw "name not found";
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
		enter_names();
		std::cout<<"List : \n";
		print(name,age);
		std::vector<std::string> name_=name;
		std::vector<double> age_=age;
		sort(name.begin(),name.end());
		for (int i=0; i<int(name.size()); ++i)
			age[i]=age_[find_index(name_,name[i])];
		std::cout<<"\nAfter sorting:\n";
		print(name,age);
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
	return 0;
}
