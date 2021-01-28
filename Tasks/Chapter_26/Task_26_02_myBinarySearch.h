#ifndef TASK_26_02_MYBINARYSEARCH_H
#define TASK_26_02_MYBINARYSEARCH_H

#ifndef TASK_26_02_STDAFX_H
#include "Task_26_02_stdafx.h"
#endif

template<typename Iter, typename T>
bool myBinarySearch(Iter first, Iter last, const T& val)
{
	if (first == last)
	{
		return false;
	}
	if (*(--last) < val)
	{
		return false;
	}
	Iter low = first;
	Iter high = last;
	while (true)
	{
		if (low == high)
		{
			return false;
		}
		int distance = 0;
		Iter f = low;
		while (f != high)
		{
			++f;
			++distance;
		}
		Iter lowTemp = low;
		std::advance(lowTemp, distance / 2);
		Iter mid = lowTemp;
		T guess = *mid;
		if (guess == val)
		{
			return true;
		}
		if (guess > val)
		{
			--mid;
			high = mid;
		}
		else
		{
			++mid;
			low = mid;
		}
	}
	return false;
}

template<typename T>
struct Test
{
	std::string label;
	T val;
	std::vector<T> seq;
	bool res;
};

template<typename T>
std::istream& operator>>(std::istream& inputStream, Test<T>& test)
{
	if (!inputStream)
	{
		return inputStream;
	}
	char ch1;
	char ch2;
	std::string label;
	T val;
	inputStream >> ch1 >> label >> val >> ch2;
	if (!inputStream || ch1 != '{' || ch2 != '{')
	{
		return inputStream;
	}
	std::vector<T> seq;
	bool res;
	T seqValue;
	while (inputStream >> seqValue)
	{
		seq.push_back(seqValue);
		while (inputStream.peek() == ' ')
		{
			inputStream.ignore();
		}
		if (inputStream.peek() == '}')
		{
			break;
		}
	}
	inputStream >> ch1 >> res >> ch2;
	if (!inputStream || ch1 != '}' || ch2 != '}')
	{
		return inputStream;
	}
	test.label = label;
	test.val = val;
	test.seq = seq;
	test.res = res;
	return inputStream;
}

template<typename T>
unsigned int test(std::ifstream& inputStream)
{
	unsigned int errors = 0;
	for (Test<T> t; inputStream >> t; )
	{
		bool r = myBinarySearch(t.seq.begin(), t.seq.end(), t.val);
		if (r != t.res)
		{
			std::cout << "failure: test " << t.label <<
				" binary_search: " << t.seq.size() <<
				" elements, val = " << t.val <<
				" -> " << t.res << '\n';
			++errors;
		}
	}
	return errors;
}

#endif