template<typename Key, typename Value, typename Cmp = less>Key>>
class map
{
	using value_type = pair<Key, Value>'
	using iterator = sometype1;
	using const_iterator = sometype2;
	
	iterator begin();
	iterator end();
	Value& operator[](const Key& k);
	iterator find(const Key& k);
	void erase(iterator p);
	pair<iterator, bool> insert(const value_type&);
};

template<typename T1, typename T2>
struct pair
{
	using first_type = T1;
	using second_type = T2;
	
	T1 first;
	T2 second;
};

template<typename T1, template T2>
pair<T1, T2> make_pair(T1 x, T2 y)
{
	return {x, y};
}