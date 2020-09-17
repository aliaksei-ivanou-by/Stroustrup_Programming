#ifndef BOOK_19_06_VECTOR
#define BOOK_19_06_VECTOR

#ifndef BOOK_19_06_STDAFX
#include "Book_19_06_stdafx.h"
#endif

template<class T, class A = std::allocator<T>>
class vector
{
private:
	A alloc;
	int sz;
	T* elem;
	int space;
public:
	vector();
	explicit vector(int s);
	vector(std::initializer_list<T> lst);
	//vector(const vector& a);
	//vector& operator=(const vector& a);
	//vector(const vector&& a);
	//vector& operator=(const vector&& a);
	~vector();
	const size_t size() const;
	const int capacity() const;
	void reserve(int newalloc);
	void push_back(const T& val);
	void resize(int newsize, T val = T());
	T& at(int n);
	const T& at(int n) const;
	T& operator[](int n);//
	const T& operator[](int n) const;
};

#endif
