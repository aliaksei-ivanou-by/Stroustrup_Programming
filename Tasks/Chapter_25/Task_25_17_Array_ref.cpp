#include <iostream>
#include <vector>
#include "GUI/Graph.h"

template<typename T>
class Array_ref
{
public:
	Array_ref(T* pp, int s) :
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
	int size() const
	{
		return sz;
	}
private:
	T* p;
	int sz;
};

template<typename T>
Array_ref<T> make_ref(T* pp, int s)
{
	return (pp) ? Array_ref<T>(pp, s) : Array_ref<T>(nullptr, 0);
}

template<typename T>
Array_ref<T> make_ref(std::vector<T>& v)
{
	return (v.size()) ? Array_ref<T>(&v[0], v.size()) : Array_ref<T>(0, 0);
}

template<typename T, int s>
Array_ref<T> make_ref(T(&pp)[s])
{
	return Array_ref<T>(pp, s);
}

void test(std::vector<Graph_lib::Circle*> shapes, Graph_lib::Shape* shape)
{
	shapes.emplace_back(make_ref(shape, 1)); // Error - cannot convert from '_Ty' to '_Objty'
	// The element is constructed in-place,
	// i.e. no copy or move operations are performed.
	// The constructor of the element is called with exactly the same arguments,
	// as supplied to the function.
}

int main()
try
{
	Graph_lib::Rectangle* rectangle = new Graph_lib::Rectangle(Point(10, 10), 10, 100);
	std::vector<Graph_lib::Circle*> shapes;

	test(shapes, rectangle);
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}