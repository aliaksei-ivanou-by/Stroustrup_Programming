template<typename T>
class list
{
public:
	class Link;
	using size_type = unsigned long;
	using value_type = T;
	class iterator;
	class const_iterator;
	
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	
	size_type size();
};