#include "iostream"

void sizes(char ch, int I, int* p1, bool b, double d, long long int lli, double* p2)
{
	std::cout<<"Char size = "<<sizeof(char)<<" - "<<sizeof(ch)<<"\n";
	std::cout<<"Int size = "<<sizeof(int)<<" - "<<sizeof(I)<<"\n";
	std::cout<<"Int* size = "<<sizeof(int*)<<" - "<<sizeof(p1)<<"\n";
	std::cout<<"Bool size = "<<sizeof(bool)<<" - "<<sizeof(b)<<"\n";
	std::cout<<"Double size = "<<sizeof(double)<<" - "<<sizeof(d)<<"\n";
	std::cout<<"Long long int size = "<<sizeof(double)<<" - "<<sizeof(lli)<<"\n";
	std::cout<<"Double* size = "<<sizeof(double*)<<" - "<<sizeof(p2)<<"\n";
}

int main()
{
	char ch='a';
	int I=2;
	int* p1=&I;
	bool b=true;
	double d=3.14159;
	long long int lli=232321;
	double* p2=&d;
	sizes(ch, I, p1, b, d, lli, p2);
}
