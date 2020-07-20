// Выявление повторяющихся слов
#include "iostream"
int main()
{
	std::string previous=" "; // Переменная инициализирована не словом
	std::string current; // Текущее слово
	while(std::cin>>current) // Считываем поток слов
	{
		if (previous==current) // Проверяем совпадение с предыдущим словом
			std::cout<<"Repeating word: "<<current<<"\n";
		previous=current;
	}
	return 0;
}
