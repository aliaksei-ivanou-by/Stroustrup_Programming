#include "iostream"
long long int factorial(int n);
long long int permutations(int a, int b);
long long int combinations(int a, int b);

int error_num;
int error_factorial;
int error_permutations;

int main()
{
	try
	{
		long long int a=0, b=0;
		while (std::cin)
		{
			error_num=0;
			error_factorial=0;
			error_permutations=0;
			std::cout<<"Enter two integers to get permutations or combinations from:\n";
			std::cin>>a>>b;
			if (!std::cin)
			{
				std::cout<<"Numbers, please!\n";
				std::cin.clear();
				std::cin.ignore(10000,'\n');
			}
			else
			{
				char ch=0;
				std::cout<<"(P)ermutations or (c)ombinations?\n";
				std::cin>>ch;
				long long int result=0;
				switch (ch)
				{
				case 'p': case 'P':
					result=permutations(a,b);
					if (error_num!=0)
					{
						break;
					}
					std::cout<<"P("<<a<<','<<b<<") = "<<result<<"\n";
					break;
				case 'c': case 'C':
					result=combinations(a,b);
					if (error_num!=0)
					{
						break;
					}
					std::cout<<"C("<<a<<','<<b<<") = "<<result<<"\n";
					break;
				default:
					std::cout<<"Illegal choice for 'p' or 'c'\n";
					std::cin.ignore(10000,'\n');
					break;
				}
			}
		}
		return 0;
	}
	catch (const char* msg)
	{
		std::cout<<msg;
		error_num++;
	}
}

long long int factorial(int n)
{
	try
	{
		if (n==0)
			return 1;
		else
			if (n<0)
			{
				throw "You entered a negative number\n";
			}
			else
				if (n==1)
					return 1;
				else
					return n*factorial(n-1);
	}
	catch (const char* msg)
	{
		error_num++;
		error_factorial++;
		if (error_factorial==1)
			std::cout<<msg;
		return 0;
	}
}

long long int permutations(int a, int b)
{
	try
	{
		if (a<b)
		{
			throw "Wrong input numbers\n";
		}
		long long int result=double(factorial(a))/double(factorial(a-b));
		return result;
	}
	catch (const char* msg)
	{
		error_num++;
		error_permutations++;
		if (error_permutations==1)
			std::cout<<msg;
		return 0;
	}
}

long long int combinations(int a, int b)
{
	long long int result=double(permutations(a,b))/double(factorial(b));
	return result;
}
