#include <iostream>

template<class T>
class my_vector
{
private:
	size_t sz;
	T* elem;
	size_t space;
public:
	class iterator;
	my_vector() :
		sz{ 0 },
		elem{ nullptr },
		space{ 0 }
	{}
	explicit my_vector(size_t n) :
		sz{ n },
		elem{ std::make_unique<T[]>(n).release() },
		space{ n }
	{
		for (auto i = begin(); i != end(); ++i)
		{
			*i = T();
		}
	}
	my_vector(const my_vector& v) :
		sz{ v.sz },
		elem{ std::make_unique<T[]>(v.sz).release() },
		space{ v.sz }
	{
		std::copy(v.elem, v.elem + v.sz, elem);
	}
	T& operator[](int n)
	{
		return elem[n];
	}
	T& operator[](int n) const
	{
		return elem[n];
	}
	iterator begin()
	{
		return iterator(elem, elem, sz);
	}
	iterator begin() const
	{
		return iterator(elem, elem, sz);
	}
	iterator end()
	{
		return iterator(elem + sz, elem, sz);
	}
	iterator end() const
	{
		return iterator(elem + sz, elem, sz);
	}
	size_t size() const
	{
		return sz;
	}
	size_t capacity() const
	{
		return space;
	}
};

template<typename T>
class my_vector<T>::iterator
{
private:
	T* curr;
	T* first;
	T* last;
public:
	iterator(T* p, T* elem, size_t sz) :
		curr{ p },
		first{ elem },
		last{ elem + sz }
	{}
	iterator& operator++()
	{
		if (curr == last)
		{
			throw std::out_of_range("bad iterator _ out of range");
		}
		++curr;
		return *this;
	}
	iterator& operator--()
	{
		if (curr == first)
		{
			throw std::out_of_range("bad iterator _ out of range");
		}
		--curr;
		return *this;
	}
	T& operator*()
	{
		return *curr;
	}
	T& operator*() const
	{
		return *curr;
	}
	bool operator==(const iterator& other) const
	{
		return curr == other.curr;
	}
	bool operator!=(const iterator& other) const
	{
		return curr != other.curr;
	}
	auto operator[](int n)
	{
		auto myCurr = curr + n;
		if (myCurr < first || myCurr > last)
		{
			throw std::out_of_range("bad iterator _ out of range");
		}
		return myCurr;
	}
	auto operator[](int n) const
	{
		auto myCurr = curr + n;
		if (myCurr < first || myCurr > last)
		{
			throw std::out_of_range("bad iterator _ out of range");
		}
		return myCurr;
	}
};

int main(int argc, char** argv)
try
{
	int n = 10;
	my_vector<int> myVector(n);
	for (int i = 0; i < n; ++i)
	{
		myVector[i] = i;
	}

	std::cout << "myVector size:\t" << myVector.size() << '\n';

	std::cout << "myVector" << '\t';
	for (const auto& i : myVector)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';

	try
	{
		auto myIterator = myVector.begin();
		--myIterator;
	}
	catch (std::out_of_range)
	{
		std::cout << "Decrement from begin.\tError - Out of range\n";
	}

	try
	{
		auto myIterator = myVector.end();
		++myIterator;
	}
	catch (std::out_of_range)
	{
		std::cout << "Decrement from end.\tError - Out of range\n";
	}

	try
	{
		auto myIterator = myVector.begin();
		auto temp = myIterator[23];
		std::cout << temp;
	}
	catch (std::out_of_range)
	{
		std::cout << "Out of range access.\tError - Out of range\n";
	}

	try
	{
		auto myIterator = myVector.begin();
		auto temp = myIterator[5];
		std::cout << *temp;
	}
	catch (std::out_of_range)
	{
		std::cout << "Out of range access.\tError - Out of range\n";
	}
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