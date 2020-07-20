#include "iostream"
int main()
{
	for(char n='a';n<='z';++n)
		std::cout<<n<<" "<<int(n)<<"\n";
	std::cout<<"\n\n";
	for(char n='A';n<='Z';++n)
		std::cout<<n<<" "<<int(n)<<"\n";
	for(char n='0';n<='9';++n)
		std::cout<<n<<" "<<int(n)<<"\n";
	return 0;
}
