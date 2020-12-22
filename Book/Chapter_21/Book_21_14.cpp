template<typename In, typename In2, typename T, typename BinOp, typename BinOp2>
T inner_product(In first, In last, In2 first2, T init, BinOp op, BinOp2 op2)
{
	while (first != last)
	{
		init = op(init, op2(*first, *first2));
		++first;
		++first2;
	}
	return init;
}