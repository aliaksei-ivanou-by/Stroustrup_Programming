#include <iostream>
#include <set>

struct Fruit
{
	std::string name;
	int count;
	double unit_price;
	Fruit(const std::string& n, const int c = 0, const double u_p = 0.0):
		name{ n },
		count{ c },
		unit_price{ u_p }
	{}
	friend std::ostream& operator<< (std::ostream& outputStream, const Fruit* fruit)
	{
		return outputStream
			<< fruit->name << '\t'
			<< fruit->count << '\t'
			<< fruit->unit_price;
	}
};

struct Fruit_comparison
{
	bool operator()(const Fruit* a, const Fruit* b) const
	{
		return a->name < b->name;
	}
};

int main()
try
{
	std::set<Fruit*, Fruit_comparison> inventory;
	inventory.insert(new Fruit("quince", 5));
	inventory.insert(new Fruit("apple", 200, 0.37));
	for (const auto& i : inventory)
	{
		std::cout << i << '\n';
	}
	for (const auto& i : inventory)
	{
		delete i;
	}
	inventory.clear();
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}