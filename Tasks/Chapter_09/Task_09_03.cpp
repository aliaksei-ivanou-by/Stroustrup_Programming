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
std::ostream& operator<<(std::ostream& os, const Name_pairs& np)
{
    if (np.get_name().size()!=np.get_age().size())
        throw "<<: name and age must be the same size";
    for (int i=0; i<int(np.get_name().size()); ++i)
    	os<<'('<<np.get_name()[i]<<','<<np.get_age()[i]<<')'<<"\n";
    return os;
}

bool operator==(const Name_pairs& a, const Name_pairs& b)
{
    if (a.get_name().size()!=b.get_name().size() || a.get_age().size()!=b.get_age().size())
        return false;
    bool equal=true;
    for (int i=0; i<int(a.get_name().size()); ++i)
    {
        if (a.get_name()[i]!=b.get_name()[i])
            return false;
    }
    for (int i=0; i<int(a.get_age().size()); ++i)
    {
        if (a.get_age()[i]!=b.get_age()[i])
            return false;
    }
    return true;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b)
{
    return !(a==b);
}

int main()
try
{
	Name_pairs pair_1;
	pair_1.read_names();
	pair_1.read_ages();
	Name_pairs pair_2;
	pair_2.read_names();
	pair_2.read_ages();
	std::cout << "pair_1:\n" << pair_1;
	std::cout << "pair_2:\n" << pair_2;
	if (pair_1==pair_2)
		std::cout<<"Identical!\n";
	if (pair_1!=pair_2)
		std::cout<<"Not identical!\n";
}
catch (const char* msg)
{
	std::cout<<msg;
}
