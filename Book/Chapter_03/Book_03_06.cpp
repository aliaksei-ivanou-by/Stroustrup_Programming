// Ввод и сравнение имен
#include "iostream"
int main()
{
	std::cout<<"Please, enter 2 names:\n";
	std::string first;
	std::string second;
	std::cin>>first>>second; // Считываем 2 строки
	if (first==second) std::cout<<"Names are equal\n";
	if (first<second)
		std::cout<<first<<" precede "<<second<<"\n";
	if (first>second)
		std::cout<<first<<" follows "<<second<<"\n";
	return 0;
}
