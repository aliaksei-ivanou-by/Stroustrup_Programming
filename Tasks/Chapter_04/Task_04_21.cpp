#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
int main()
{
	std::vector<std::string> names;
	std::vector<int> scores;
	int k=1;
	std::cout<<"Please, enter a name and a score : \n";
	std::string name;
	int score;
	while (true)
	{
		std::cin>>name>>score;
		if (name=="NoName" && score==0)
			break;
		std::cout<<"name : "<<name<<", score : "<<score<<"\n";
		names.push_back(name);
		scores.push_back(score);
	}
	std::vector<std::string> names_sort=names;
	std::sort(names_sort.begin(), names_sort.end()), std::greater<std::string>();
	for (int i=1; i<names_sort.size(); i++)
	{
		if (names_sort[i]==names_sort[i-1])
		{
			std::cout<<"Error. Repeating name.\n";
			k=0;
			break;
		}
	}
	if (k!=0)
	{
		std::cout<<"\nAll scores : \n";
		for (int i=0; i<names.size(); i++)
		{
			std::cout<<names[i]<<" : "<<scores[i]<<"\n";
		}
	}
	if (k!=0)
	{
		while (true)
		{
			std::cout<<"Please, enter a name or 'exit' to exit: \n";
			std::string name_search;
			std::cin>>name_search;
			if (name_search=="exit")
				break;
			int key=0;
			for (int i=0; i<names.size(); i++)
			{
				if (names[i]==name_search)
				{
					std::cout<<names[i]<<" : "<<scores[i]<<"\n";
				}
				else
				{
					key++;
				}
				if (key==names.size())
					std::cout<<"No this name.\n";
			}
		}
	}
	if (k!=0)
		{
			while (true)
			{
				std::cout<<"Please, enter a score or '-1' to exit: \n";
				int score_search;
				std::cin>>score_search;
				if (score_search==-1)
					break;
				int key=0;
				for (int i=0; i<scores.size(); i++)
				{
					if (scores[i]==score_search)
					{
						std::cout<<names[i]<<" : "<<scores[i]<<"\n";
					}
					else
						key++;
				}
				if (key==scores.size())
					std::cout<<"No this score.\n";
			}
		}
	return 0;
}
