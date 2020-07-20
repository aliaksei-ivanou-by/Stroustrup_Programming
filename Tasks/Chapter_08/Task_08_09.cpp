#include "iostream"
#include "vector"

int maxv(const std::vector<int>& v)
{
	try
	{
		if (v.size()==0)
			throw "maxv: argument vector is empty";
		int v_max=v[0];
		if (v.size()==1)
			return v_max;
		for (int i=1; i<int(v.size()); ++i)
			if (v[i]>v_max)
				v_max=v[i];
		return v_max;
    }
    catch(const char* msg)
    {
    	std::cout<<msg;
    }
}

void print(const std::vector<int>& v)
 {
     std::cout<<"{ ";
     for (int i=0; i<int(v.size()); ++i)
    	 std::cout<<v[i]<<' ';
     std::cout<<" }\n";
 }

int main()
{
	try
	{
		std::vector<int> array;
		array.push_back(1);
		array.push_back(2);
		array.push_back(4);
		array.push_back(6);
		array.push_back(8);
		array.push_back(87);
		array.push_back(15);
		array.push_back(1);
		array.push_back(10);
		array.push_back(17);
		print(array);
		std::cout<<maxv(array)<<"\n";
		return 0;
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}
