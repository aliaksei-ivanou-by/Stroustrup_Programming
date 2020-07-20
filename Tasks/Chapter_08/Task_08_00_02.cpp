#include "iostream"

void swap_v(int a, int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
};

void swap_r(int& a, int& b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
};


void swap_cr(const int& a, const int& b)
{
	int temp;
	temp=a;
	//a=b;
	//b=temp;
}

int main()
{
	int x=7;
	int y=9;
	std::cout<<"x="<<x<<", y="<<y<<"\n";
	swap_r(x, y);
	std::cout<<"x="<<x<<", y="<<y<<"\n";
	swap_v(7, 9);
	const int cx=7;
	const int cy=9;
	std::cout<<"cx="<<cx<<", cy="<<cy<<"\n";
	swap_cr(x, y);
	std::cout<<"cx="<<cx<<", cy="<<cy<<"\n";
	swap_v(7.7, 9.9);
	double dx=7.7;
	double dy=9.9;
	std::cout<<"dx="<<dx<<", dy="<<dy<<"\n";
	swap_cr(dx, dy);
	std::cout<<"dx="<<dx<<", dy="<<dy<<"\n";
	swap_cr(7.7, 9.9);
	std::cout<<"\n\n";
}
