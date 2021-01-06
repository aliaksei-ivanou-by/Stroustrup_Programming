void better2(const Array_ref<Shape* const> a)
{
	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i])
		{
			a[i]->draw();
		}
	}
}

template<typename T>
class Array_ref
{
	public:
	// ...
	template<typename Q>
	operator const Array_ref<const Q>()
	{
		static_cast<Q>(*static_cast<T*>(nullptr));
		return Array_ref<const Q>(reinterpret_cast<Q*>(p), sz);
	}
	// ...
};

void f(Shape* q, vector<Circle*> s0)
{
	Polygon* s1[10];
	Shape* s2[10];
	Shape* p1 = new Rectangle{ Point{ 0, 0 }, 10 };
	better2(make_ref(s0)); // ok
	better2(make_ref(s1)); // ok
	better2(make_ref(s2)); // ok
	better2(make_ref(p1, 1)); // error
	better2(make_ref(q, max)); // error
}