// Выявление повторяющихся слов
#include "iostream"
int main()
{
	int number_of_words=0;
	std::string previous=" "; // Переменная инициализирована не словом
	std::string current; // Текущее слово
	while(std::cin>>current) // Считываем поток слов
	{
		++number_of_words; // Увеличиваем счетчик слов
		if (previous==current) // Проверяем совпадение с предыдущим словом
			std::cout<<"Repeating word: "<<current
			<<" after "<<number_of_words<<" words.\n";
		previous=current;
	}
	return 0;
}
