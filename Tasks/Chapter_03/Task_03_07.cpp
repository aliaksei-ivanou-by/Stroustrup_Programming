#include "iostream"
int main()
{
	std::string a=" ", b=" ", c=" ";
	std::cout<<"Enter a\n";
	std::cin>>a;
	std::cout<<"Enter b\n";
	std::cin>>b;
	std::cout<<"Enter c\n";
	std::cin>>c;
	if ((a<c)&&(b<c))
	{
		if (a<b)
		{
	        std::cout<<a<<", "<<b<<", "<<c<<"\n";
	    }
	    if (a>b)
	    {
	        std::cout<<b<<", "<<a<<", "<<c<< "\n";
	    }
	    if (a==b)
	    {
	        std::cout<<a<<", "<< a << ", "<<c<<"\n";
	    }
	}
	if ((b>a)&&(b>c))
	{
	    if (a>c)
	    {
	        std::cout<<c<<", "<<a<<", "<<b<<"\n";
	    }
	    if (a<c)
	    {
	        std::cout<<a<<", "<<c<<", "<<b<<"\n";
	    }
	    if (a==c)
	    {
	        std::cout<<a<<", "<<c<<", "<<b<<"\n";
	    }
	}
	if ((b<a)&&(c<a))
	{
	    if (b<c)
	    {
	        std::cout<<b<<", "<<c<<", "<<b<<"\n";
	    }
	    if (b>c)
	    {
	        std::cout<<b<<", "<<c<<", "<<a<<"\n";
	    }
	    if (b==c)
	    {
	        std::cout<<b<<", "<<c<<", "<<a<<"\n";
	    }
	}
	if((a==b)&&(c==b)&&(b==a))
	{
	    std::cout<<"All str = "<<a<<"\n";
	}
	return 0;
}
