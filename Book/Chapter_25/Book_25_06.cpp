template<typename T>
class Array_ref
{
private:
	T* p;
	int sz;
public:
	Array_ref*(T* pp, int a):
		p{ pp },
		sz{ s }
	{}
	T& operator[](int n)
	{
		return p[n];
	}
	const T& operator[](int n) const
	{
		return p[n];
	}
	bool assign(Array_ref a)
	{
		if (a.sz != sz)
		{
			return false;
		}
		for (int i = 0; i < sz; ++i)
		{
			p[i] = a.p[i];
		}
		return true;
	}
	void reset(Array_ref a)
	{
		reset(a.p, a.sz);
	}
	void reset(T* pp, int s)
	{
		p = pp;
		sz = s;
	}
};

template<typename T>
Array_ref<T> make_ref(T* pp, int s)
{
	return (pp) ? Array_ref<T>(pp, s) : Array_ref<T>(nullptr, 0);
}

template<typename T>
Array_ref<T> make_ref(vector<T>& v)
{
	return (v.size)) ? Array_ref<T>(&v[0], v.size()) : Array_ref<T>(0, 0);
}

template<typename T, int s>
Array_ref<T> make_ref(T(&pp)[s])
{
	return Array_ref<T>(pp, s);
}

void better(Array_ref<Shape> a)
{
	for (int i = 0; i < a.size(); ++i)
	{
		a[i].draw();
	}
}
void f(Shape* q, vector<Circle>& s0)
{
	Polygon s1[10];
	Shape s2[20];
	
	Shape* p1 = new Rectangle{ Point{ 0, 0 }, Point{ 10, 20 } };
	better(make_ref(s0)); // error
	better(make_ref(s1)); // error
	better(make_ref(s2));  // error
	better(make_ref(p1, 1)); // ok
	delete p1;
	p1 = 0;
	better(make_ref(p1, 1)); // ok 
	better(make_ref(q, max)); // ok
}