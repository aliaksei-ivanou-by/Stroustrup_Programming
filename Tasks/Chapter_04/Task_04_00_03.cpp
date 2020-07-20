#include "iostream"
int main()
{
	char n='a';
	while (n<='z')
	{
		std::cout<<n<<" "<<int(n)<<"\n";
		++n;
	}
	return 0;
}
