#include "iostream"
int main()
{
	std::cout<<"Please, enter 3 int numbers : \n";
	int a=0, b=0, c=0;
	std::cin>>a>>b>>c;
	int temp=0;
	int counter=3;
	while (counter!=0)
	{
		if (a>b)
		{
			temp=a;
			a=b;
			b=temp;
			counter--;
		}
		else
		{
			if (b>c)
			{
				temp=b;
				b=c;
				c=temp;
				counter--;
			}
			else
			{
				counter=3;
				break;
			}
		}
	}
	std::cout<<a<<", "<<b<<", "<<c<<".\n";
	return 0;
}
