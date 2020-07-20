#include "iostream"
#include "vector"
#include "algorithm"

class Name_pairs
{
public:
	void read_names();
	void read_ages();
	void print() const;
	void sort();
    const std::vector<std::string>& get_name() const
    {
    	return name;
    }
    const std::vector<double>& get_age() const
    {
    	return age;
    }
private:
    std::vector<std::string> name;
    std::vector<double> age;
};

void Name_pairs::read_names()
{
	std::cout<<"Enter names or 'NoName' to finish: ";
	std::string s;
	while (std::cin>>s && s!="NoName")
	{
		for (int i=0; i<int(name.size()); ++i)
			if (name[i]==s)
				throw "Name exists already";
			name.push_back(s);
	}
}
void Name_pairs::read_ages()
{
    age=std::vector<double>();
    for (int i=0; i<int(name.size()); ++i)
    {
    	std::cout<<"Age of "<<name[i]<<": ";
    	double a;
    	std::cin>>a;
        age.push_back(a);
    }
}
void Name_pairs::print() const
{
    if (name.size()!=age.size())
        throw "print(): name and age must be the same size";
    for (int i=0; i<int(name.size()); ++i)
    {
    	std::cout<<'('<<name[i]<<','<<age[i]<<')'<<"\n";
    }
}
void Name_pairs::sort()
{
    if (name.size()!=age.size())
        throw "sort(): name and age must be the same size";
    std::vector<std::string> name_presort=name;
    std::vector<double> age_cp=age;
    std::sort(name.begin(),name.end());
    for (int i=0; i<int(name.size()); ++i)
    {
        for (int j=0; j<int(name_presort.size()); ++j)
        {
            if (name[i]==name_presort[j])
                age[i]=age_cp[j];
        }
    }
}
