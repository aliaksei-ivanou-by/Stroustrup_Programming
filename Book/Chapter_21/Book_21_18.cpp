unordered_map<string, double> dow_price;

for (const auto& p : dow_price)
{
	const string& symbol = p.first;
	cout << symbol << '\t'
		<< p.second << '\t'
		<< dow_name[symbol] << '\n';
}