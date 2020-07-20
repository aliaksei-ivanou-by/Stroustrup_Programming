#include "iostream"
#include "vector"
#include "algorithm"

struct Vector_properties
{
	Vector_properties();
	int min;
	int max;
	double mean;
	int median;
};

Vector_properties::Vector_properties()
    :min(0), max(0), mean(0), median(0) {}

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

int minv(const std::vector<int>& v)
{
	try{
		if (v.size()==0)
			throw "minv: argument vector is empty";
		int v_min=v[0];
		if (v.size()==1)
			return v_min;
		for (int i=1; i<int(v.size()); ++i)
			if (v[i]<v_min)
				v_min=v[i];
		return v_min;
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

double meanv(const std::vector<int>& v)
{
	try
	{
		if (v.size()==0)
			throw "meanv: argument vector is empty";
		double v_sum=0;
		for (int i=0; i<int(v.size()); ++i)
			v_sum+=v[i];
		return v_sum/int(v.size());
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

int medianv(std::vector<int> v)
{
	try
	{
		if (v.size()==0)
			throw "medianv: argument vector is empty";
		sort(v.begin(), v.end());
		return v[v.size()/2];
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

Vector_properties get_info(const std::vector<int>& v)
{
	Vector_properties vec_info;
	vec_info.max=maxv(v);
	vec_info.min=minv(v);
	vec_info.mean=meanv(v);
	vec_info.median=medianv(v);
    return vec_info;
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
		Vector_properties array_inf=get_info(array);
		std::cout<<"Max : "<<array_inf.max<<"\n";
		std::cout<<"Min : "<<array_inf.min<<"\n";
		std::cout<<"Mean : "<<array_inf.mean<<"\n";
		std::cout<<"Median : "<<array_inf.median<<"\n";
		return 0;
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}
