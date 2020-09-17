template<class T, class A>
struct vector_base
{
	A alloc;
	T* elem;
	int sz;
	int space;
	vector_base(const A& a, int n)
		: alloc{ a },
		elem{ a.allocate(n) },
		sz{ n },
		space{ n }
	{
	}
	~vector_base()
	{
		alloc.deallocate(elem, space);
	}
};