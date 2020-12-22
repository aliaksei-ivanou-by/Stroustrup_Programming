template<typename In, typename In2, typename T>
T inner_product(In first, In last, In2 first2, T init)
{
	while (first != last)
	{
		init = init + (*first) * (*last);
		++first;
		++first2;
	}
	return init;
}

vector<double> dow_price = { 81.86, 34.69, 54.45 };

list<double> dow_weight = {5.8549, 2.4808, 3.8940 };

double dji_index = inner_product(
					dow_price.begin(), dow_price.end(), 
					dow_weight.begin(), 0.0);
cout << "DJI = " << dji_index << '\n';