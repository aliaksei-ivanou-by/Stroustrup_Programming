template<typename In, typename T, typename BinOp>
T accumulate(In first, In last, T init, BinOp op)
{
	while (first != last)
	{
		init = op(init, *first);
		++first;
	}
	return init;
}

array<double, 4> a = { 1.1, 2.2, 3.3, 4.4 };
cout << accumulate(a.begin(), a.end(), 1.0, multiplies<double>());