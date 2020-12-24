struct Fruit
{
	string name;
	int count;
	double init_price;
	Date last_sale_date;
	// ...
};

struct Fruit_order
{
	bool operator()(const Fruit& a, const Fruit& b) const
	{
		return a.name < b.name;
	}
};

set<Fruit, Fruit_order> inventory;

inventory.insert(Fruit{ "quince", 5 });
inventory.insert(Fruit{ "apple", 200, 0.37 });

for (auto p = inventory.begin(); p != inventory.end(); ++p)
{
	cout << *p << '\n';
}