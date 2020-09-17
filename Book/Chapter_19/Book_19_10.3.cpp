template<class T, class A>
class vector : private vector_base<T, A>
{
	public:
	// ...
};

template<class T, class A>
void vector<T, A>::reserve(int newalloc)
{
	if (newalloc <= this->space)
	{
		return;
	}
	vector_base<T, A> b(this->alloc, newalloc);
	uninitialized_copy(b.elem, &b.elem[this->sz], this->elem);
	for (int i = 0; i < this->sz; ++i)
	{
		this->alloc.destroy(&this->elem[i]);
	}
	swap<vector_base<T, A>>(*this, b);
}