#include <iostream>
#include <vector>

template<typename Elem>
class ovector
{
private:
	std::vector<Elem*> vec;
public:
	ovector() :
		vec{}
	{}
	~ovector()
	{
		for (auto i = begin(); i < end(); ++i)
		{
			delete* i;
		}
	}
	auto begin()
	{
		return vec.begin();
	}
	auto begin() const
	{
		return vec.begin();
	}
	auto end()
	{
		return vec.end();
	}
	auto end() const
	{
		return vec.end();
	}
	size_t size()
	{
		return vec.size();
	}
	size_t capacity()
	{
		return vec.capacity();
	}
	void push_back(Elem* elem)
	{
		vec.push_back(elem);
	}
	Elem& operator[](int n)
	{
		return *vec[n];
	}
	Elem& operator[](int n) const
	{
		return *vec[n];
	}
};

int main()
try
{
	ovector<int> oVector;
	for (int i = 0; i < 10; ++i)
	{
		oVector.push_back(new int(i));
	}
	for (auto i = 0; i < oVector.size(); ++i)
	{
		std::cout << oVector[i] << '\n';
	}
	return 0;
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