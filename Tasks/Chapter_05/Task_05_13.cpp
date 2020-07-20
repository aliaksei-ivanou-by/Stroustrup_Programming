#include "iostream"
#include "vector"
int main()
{
	int v=1;
	int game=0;
	std::vector<int> n, guess;
	while(v==1)
	{
		guess={};
		if (game==0)
		{
			n={};
			std::cout<<"New game!\n";
			unsigned rand_value;
			std::cout<<"Please, enter a number for randomization : ";
			std::cin>>rand_value;
			std::srand(rand_value);
			n.push_back(rand()%9);
			n.push_back(rand()%9);
			if (n[1]==n[0])
				n[1]=rand()%9;
			n.push_back(rand()%9);
			if (n[2]==n[1] && n[2]==n[0])
				n[2]=rand()%9;
			n.push_back(rand()%9);
			if (n[3]==n[2] && n[3]==n[1] && n[3]==n[0])
				n[3]=rand()%9;
		}
		std::cout<<"Please, enter for game 4 numbers : \n";
		for(int i=0; i<int(n.size()); i++)
		{
			int k=0;
			std::cin>>k;
			guess.push_back(k);
		}
		//std::cout<<"Computer variant : \n";
		//for (int i : n)
		//	std::cout<<i<<" ";
		//std::cout<<"\n";
		std::cout<<"Your variant : \n";
		for (int i : guess)
			std::cout<<i<<" ";
		std::cout<<"\n";
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
		if (bull==4)
			std::cout<<"You win! Play again?\nPress '1' for new game, '2' to continue old game, '3' to exit.\n";
		else
			std::cout<<"You lose! Play again?\nPress '1' for new game, '2' to continue old game, '3' to exit.\n";
		std::cin>>v;
		if (v==1)
		{
			v=1;
			game=0;
		}
		else
			if (v==2)
			{
				v=1;
				game=1;
			}
			else
				if (v==3)
				{
					v=2;
				}
	}
	std::cout<<"Game over!\n";
	return 0;
}
