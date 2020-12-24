map<string, double> dow_price = {
	{ "MMM", 81.86 },
	{ "AA", 34.69 },
	{ "MO", 54.45 },
	// ...
};

map<string, double> dow_weight = {
	{ "MMM", 5.8549 },
	{ "AA", 2.4808 },
	{ "MO", 3.8940 },
	// ...
};

map<string, string> dow_name = {
	{ "MMM", "3M Co." },
	{ "AA", "Alcoa Inc." },
	{ "MO", "Altria Group Inc." },
	// ...
};

double alcoa_price = dow_price["AAA"];
double boeing_price = dow_price["BA"];

if (dow_price.find("INTC") != dow_price.end())
{
	cout << "Intel is found\n";
}

for (const auto& p : dow_price)
{
	const string& symbol = p.first;
	cout << symbol << '\t' 
			<< p.second << '\n'
			<< dow_name[symbol] << '\n';
}

double weighted_value(const pair<string, double>& a, const pair<string, double>& b)
{
	return a.second * b.second;
}

double dji_index = inner_product(dow_price.begin(), dow_price.end(), dow_weight.begin(), 0.0, plus<double>(), weighted_value);