template<typename Elem>
class list
{
public:
	class iterator;
	iterator begin();
	iterator end();
	iterator insert(iterator p, const Elem& v);
	iterator erase(iterator p);
	void push_back(const Elem& v);
	void push_front(const Elem& v);
	void pop_front();
	void pop_back();
	Elem& front();
	Elem& back();
};