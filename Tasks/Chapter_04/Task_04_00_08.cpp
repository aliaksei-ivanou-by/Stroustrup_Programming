#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"

int main()
{
	constexpr double M2CM=100;
	constexpr double IN2CM=2.54;
	constexpr double FT2IN=12;
    double a;
    std::string a_add="";
    char a_add_upd;
    int key=0;
    std::vector<double> num;
    while(std::cin>>a>>a_add && (a!='|') && (a_add!="|"))
    {
    	if (a_add=="cm")
    		a_add_upd='c';
    	else
    		if (a_add=="ft")
    			a_add_upd='f';
    		else
    			if (a_add=="in")
    				a_add_upd='i';
    			else
    				if (a_add=="m")
    					a_add_upd='m';
    				else
    					a_add_upd='-1';
    	switch (a_add_upd)
    	{
    	case 'c':
    		a=a/M2CM;
    		++key;
    		std::cout<<key<<" double number : ";
    		std::cout<<a<<"\n";
    		num.push_back(a);
    		std::sort(num.begin(), num.end());
    		if (key>1)
    		{
    			if (a==num[0])
    				std::cout<<a<<" is min of array.\n";
    			if (a==num[num.size()-1])
    				std::cout<<a<<" is a max of array.\n";
    		}
    		break;
    	case 'i':
    		a=a*IN2CM/M2CM;
    		++key;
    		std::cout<<key<<" double number : ";
    		std::cout<<a<<"\n";
    		num.push_back(a);
    		std::sort(num.begin(), num.end());
    		if (key>1)
    		{
    			if (a==num[0])
    				std::cout<<a<<" is min of array.\n";
    			if (a==num[num.size()-1])
    				std::cout<<a<<" is a max of array.\n";
    		}
    		break;
    	case 'f':
    		a=a*FT2IN*IN2CM/M2CM;
    		++key;
    		std::cout<<key<<" double number : ";
    		std::cout<<a<<"\n";
    		num.push_back(a);
    		std::sort(num.begin(), num.end());
    		if (key>1)
    		{
    			if (a==num[0])
    				std::cout<<a<<" is min of array.\n";
    			if (a==num[num.size()-1])
    				std::cout<<a<<" is a max of array.\n";
    		}
    		break;
    	case 'm':
    		a=a;
    		++key;
    		std::cout<<key<<" double number : ";
    		std::cout<<a<<"\n";
    		num.push_back(a);
    		std::sort(num.begin(), num.end());
    		if (key>1)
    		{
    			if (a==num[0])
    				std::cout<<a<<" is min of array.\n";
    			if (a==num[num.size()-1])
    				std::cout<<a<<" is a max of array.\n";
    		}
    		break;
    	default:
    		std::cout<<"Sorry, I don't know this. Please, enter a number again."<<"\n";
    		break;
    	}

    }
    std::sort(num.begin(), num.end());
    std::cout<<"Min of array is : "<<num[0]<<".\n";
    std::cout<<"Max of array is : "<<num[num.size()-1]<<".\n";
    std::cout<<"Number of numbers is : "<<key<<".\n";
    double sum=0;
    for (double i : num)
    {
    	sum+=i;
    }
    std::cout<<"Sum of array : "<<sum<<".\n";
    std::cout<<"Array : \n";
    for (double i : num)
    {
    	std::cout<<i<<" ";
    }
    std::cout<<"\n";
   	std::cout<<"Exit";
    return 0;
}
