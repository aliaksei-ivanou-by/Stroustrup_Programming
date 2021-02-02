#include <iostream>

template<typename T, int N>
class Pool
{
private:
	T* pool;
	size_t sz;
	size_t cap;
public:
	Pool() :
		pool{ new T[N] },
		sz{ 0 },
		cap{ N }
	{}
	~Pool()
	{
		delete[] pool;
	}
	T* get_value()
	{
		return &pool[sz++];
	}
	void free(T* value)
	{
		*value = T();
		--sz;
	}
	int available() const
	{
		return (cap - sz);
	}
};

template<typename T, int N>
class vector
{
private:
	T* elem;
	size_t sz;
	Pool<T, N> allocator;
public:
	vector():
		elem{ nullptr },
		sz{ 0 }
	{}
	void push_back(T value)
	{
		if (sz == N)
		{
			std::cout << "Error. Vector is full\n";
			return;
		}
		auto temp = allocator.get_value();
		if (!elem)
		{
			elem = temp;
		}
		*temp = value;
		++sz;
	}
	void pop_back()
	{
		if (sz < 1)
		{
			std::cout << "Error. Vector is empty\n";
			return;
		}
		elem[sz - 1] = 0;
		--sz;
		allocator.free(&elem[sz - 1]);
	}
	int size() const
	{
		return sz;
	}
	T& operator[](size_t n)
	{
		return elem[n];
	}
	const T& operator[](size_t n) const
	{
		return elem[n];
	}
	void print() const
	{
		for (auto i = 0; i < sz; ++i)
		{
			std::cout << elem[i] << ' ';
		}
		std::cout << '\n';
	}
};

int main()
try
{
	constexpr int size = 1000;
	vector<int, size> vec;
	std::cout << "Empty vector\n";
	vec.print();

	vec.pop_back();

	for (auto i = 0; i < size; ++i)
	{
		vec.push_back(i);
	}
	std::cout << "Full vector\n";
	vec.print();
	
	vec.pop_back();
	vec.push_back(999);
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
