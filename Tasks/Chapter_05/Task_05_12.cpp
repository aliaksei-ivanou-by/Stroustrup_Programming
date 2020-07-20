#include "iostream"
#include "vector"
int main()
{
	std::vector<int> n, guess;
	n={0, 6, 7, 1};
	std::cout<<"Please, enter for game 4 numbers : \n";
	for(int i=0; i<int(n.size()); i++)
	{
		int k=0;
		std::cin>>k;
		guess.push_back(k);
	}
	int bull=0;
	for (int i=0; i<int(n.size()); i++)
	{
		if (guess[i]==n[i])
			bull++;
	}
	int cow=0;
	for (int i=0; i<int(n.size()); i++)
	{
		for (int j=0; j<int(n.size()); j++)
		{
			if (guess[i]==n[j] && i!=j)
				cow++;
		}
	}
	if (cow>0 || bull>0)
	{
		std::cout<<"Bull : "<<bull<<".\n";
		std::cout<<"Cow : "<<cow<<".\n";
	}
	else
		std::cout<<"Nothing is guessed.\n";
	return 0;
}
