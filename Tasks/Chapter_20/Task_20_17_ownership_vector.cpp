#include <iostream>
#include <vector>

template<typename Elem>
class ownership_vector
{
private:
	std::vector<Elem*> vec;
	std::vector<Elem*> owned;
public:
	ownership_vector() :
		vec{},
		owned{}
	{}
	~ownership_vector()
	{
		for (size_t i = 0; i < owned.size(); ++i)
		{
			delete owned[i];
		}
	}
	void push_back(Elem& elem)
	{
		vec.push_back(&elem);
	}
	void push_back(Elem* elem)
	{
		vec.push_back(elem);
		owned.push_back(elem);
	}
	size_t size()
	{
		return vec.size();
	}
	size_t size_owned()
	{
		return owned.size();
	}
	Elem& operator[](int i)
	{
		return *vec[i];
	}
	Elem& operator[](int i) const
	{
		return *vec[i];
	}
};

int main()
try
{
	ownership_vector<int> myVector;
	myVector.push_back(new int(1));
	myVector.push_back(new int(2));
	int n = 2;
	myVector.push_back(n);
	++n;
	myVector.push_back(n);
	++n;
	myVector.push_back(n);
	for (auto i = 0; i < myVector.size(); ++i)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
	
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