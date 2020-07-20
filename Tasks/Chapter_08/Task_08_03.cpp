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

void fibonacci(int x, int y, std::vector<int>& v, const int& n)
{
	try
	{
		if (n<1)
			throw "There must be at least one number in the series";
		v.push_back(x);
		if (n==1)
			return;
		v.push_back(y);
		if (n==2)
			return;
		for (int i=2; i<n; ++i)
			v.push_back(v[i-2]+v[i-1]);
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
		int x=0, y=0, n=0;
		std::vector<int> v;
		std::cout<<"Enter first number in Fibonacci sequence: ";
		std::cin>>x;
		std::cout<<"Enter second number in Fibonacci sequence: ";
		std::cin>>y;
		std::cout<<"Enter number of elements in sequence: ";
		std::cin>>n;
		fibonacci(x,y,v,n);
		std::string s="Fibonacci sequence: ";
		print(s,v);
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}
