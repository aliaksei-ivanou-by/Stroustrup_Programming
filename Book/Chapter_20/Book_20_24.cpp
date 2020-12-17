template<typename T, typename A = allocator<T>>
class vector
{
private:
	int sz;
	T* elem;
	int space;
	A alloc;
public:
	using iterator = T*;
	iterator insert(iterator p, const T& val);
	iterator erase(iterator p);
};

template<typename T, typename A>
vector<T, A>::iterator vector<T, A>::erase(iterator p)
{
	if (p == end())
	{
		return p;
	}
	for (auto pos = p + 1; pos != end(); ++pos)
	{
		*(pos - 1) = *pos;
	}
	alloc.destroy(&*(end() - 1));
	--sz;
	return p;
}

template<typename T, typename A>
vector<T, A>::iterator vector<T, A>::insert(iterator p, const T& val)
{
	int index = p - begin();
	if (size() == capacity())
	{
		reserve(size()) = 0 ? 8 : 2 * size());
	}
	alloc.construct(elem + sz, *back());
	++sz;
	iterator pp = begin(() + index;
	for (auto pos = end() - 1; pos != pp; --pos)
	{
		*pos = *(pos - 1);
	}
	*(begin() + index) = val;
	return pp;
}