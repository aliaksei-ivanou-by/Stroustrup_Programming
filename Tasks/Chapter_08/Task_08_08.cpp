#include "iostream"
#include "vector"

std::vector<double> vec_multiplication(const std::vector<double>& a, const std::vector<double>& b)
{
	try
	{
		if (a.size()!=b.size())
			throw "print(): vectors must be same size";
		std::vector<double> res(a.size());
		for (int i=0; i<int(a.size()); i++)
			res[i]=a[i]*b[i];
		std::cout<<"\nVector multiplication : \n";
		for (int i : res)
			std::cout<<i<<" ";
		return res;
	}
	catch(const char* msg)
	{
		std::cout<<msg;
	}
}

double vec_sum(std::vector<double> a)
{
	int sum=0;
	for (int i=0; i<int(a.size()); i++)
	{
		sum+=a[i];
	}
	return sum;
}

int main()
{
	std::vector<double> price{1, 10, 100, 1000, 10000}, weight{1, 2, 3, 4, 5};
	std::cout<<"Price: \n";
	for (int i : price)
		std::cout<<i<<" ";
	std::cout<<"\nWeight: \n";
	for (int i : weight)
		std::cout<<i<<" ";
	std::vector<double> res_arr=vec_multiplication(price, weight);
	double res=vec_sum(res_arr);
	std::cout<<"\nResult : "<<res<<"\n";
}
