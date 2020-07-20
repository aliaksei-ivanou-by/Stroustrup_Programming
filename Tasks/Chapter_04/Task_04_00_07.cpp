#include "iostream"
#include "vector"
int main()
{
    double a, b;
    while(std::cin>>a>>b && (a!='|' && b!='|'))
    {
    	std::cout<<"2 double numbers : ";
        std::cout<<a<<", "<<b<<"\n";
    	if (a<b)
    	{
    		std::cout<<"Min number is "<<a<<".\n";
    		std::cout<<"Max number is "<<b<<".\n";
        	if ((b-a)<=1.0/100)
        		std::cout<<"The numbers are almost equal.\n";
    	}
    	else
    	{
    		std::cout<<"Min number is "<<b<<".\n";
    		std::cout<<"Max number is "<<a<<".\n";
    		if ((a-b)<=1.0/100)
    			std::cout<<"The numbers are almost equal.\n";
    	}
    	if (a==b)
    		std::cout<<"The numbers are equal.\n";
    }
    return 0;
}
