#include "iostream"
int f(int, int, int);
int area(int, int);
int framed_area(int, int);
int main()
{
	int a=f(1, 2, 3);
	return 0;
}

int f(int x, int y, int z)
{
	int area1=area(x,y);
	if (area1<=0)
	{
		std::cout<<"error";
		return 0;
	}
	int area2=framed_area(1,z);
	int area3=framed_area(y,z);
	double ratio=double(area1)/area3;
	int res=ratio;
	return res;
}
int area(int x, int y)
{
	if (x<=0 || y<=0)
		{
			std::cout<<"Error";
			return 0;
		}
	return x*y;
}
int framed_area(int x, int y)
{
	constexpr int frame_width=2;
	return (area-frame_width, y-frame_width);
}
