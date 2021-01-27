#ifndef TASK_21_00_05_STDAFX_H
#include "Task_21_00_05_stdafx.h"
#endif

int main()
try
{
	std::unordered_map<std::string, double> dow_price =
	{
		{ "MMM", 81.86 },
		{ "AA", 34.69 },
		{ "MO", 54.45 },
		{ "INTC", 46.85 },
		{ "KO", 53.30 }
	};
	std::unordered_map<std::string, double> dow_weight =
	{
		{ "MMM", 5.8549 },
		{ "AA", 2.4808 },
		{ "MO", 3.8940 },
		{ "INTC", 1.01 },
		{ "KO", 1.16 }
	};
	std::unordered_map<std::string, std::string> dow_name =
	{
		{ "MMM", "3M Co." },
		{ "AA", "Alcoa Inc." },
		{ "MO", "Altria Group Inc." },
		{ "INTC", "Intel Corp." },
		{ "KO", "Coca-Cola Co." }
	};
	for (auto p = dow_price.begin(); p != dow_price.end(); ++p)
	{
		const std::string& symbol = p->first;
		std::cout << symbol << '\t' << p->second << '\t' << dow_name[symbol] << '\n';
	}
	double dji_index =
		inner_product(dow_price.begin(), dow_price.end(),
			dow_weight.begin(),
			0.0,
			std::plus<double>(),
			weighted_value);
	std::cout << "\nDJI index is " << dji_index << "\n";
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