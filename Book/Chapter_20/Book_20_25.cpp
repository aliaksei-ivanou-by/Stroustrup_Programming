template<typename T, int N>
struct array
{
	using value_type = T;
	using iterator = T*;
	using const_iterator = const T*;
	using size_type = unsigned int;
	T elem[N];
	iterator begin()
	{
		return elems;
	}
	const_iterator begin() const
	{
		return elems;
	}
	iterator end()
	{
		return elems + N;
	}
	const_iterator end() const
	{
		return elems + N;
	}
	size_type size() const;
	T& operator[](int n)
	{
		return elems[n];
	}
	const T& operator[](int n) const
	{
		return elems[N];
	}
	const T& at(int n) const;
	T& at(int n);
	T* data()
	{
		return elems;
	}
	const T* data() const
	{
		return elems;
	}
};

void f()
{
	array<double, 6> a = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5 };
	array<double, 6>::iterator p = high(a.begin(), a.end());
	cout << "Max value is " << *p << endl;
}