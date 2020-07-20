#include "iostream"
#include "vector"

class Name_value
{
public:
	std::string name;
	int value;
	Name_value(std::string name_new, int value_new)
		:name(name_new), value(value_new) {}
};

int main()
{
	std::vector<Name_value> records;
	bool end=false, repeat=false;
	while(!end)
	{
		std::cout<<"Please, enter a name and a score : \n";
		std::string name;
		int score;
		std::cin>>name>>score;
		if (name=="NoName" && score==0)
			end=true;
		else
		{
			for(Name_value i : records)
				if (i.name==name)
					repeat=true;
			if (repeat)
			{
				std::cout<<"Error. Repeating name.\n";
				repeat=false;
			}
			else
			{
				records.push_back(Name_value(name, score));
			}
		}
	}
	std::cout<<"\nAll scores:\n";
	for(Name_value i : records)
	{
		std::cout<<i.name<<" - "<<i.value<<"\n";
	}
	return 0;
}
