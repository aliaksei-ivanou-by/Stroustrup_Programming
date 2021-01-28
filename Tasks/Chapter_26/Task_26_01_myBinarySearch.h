#ifndef TASK_26_01_MYBINARYSEARCH_H
#define TASK_26_01_MYBINARYSEARCH_H

#ifndef TASK_26_01_STDAFX_H
#include "Task_26_01_stdafx.h"
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

struct Test
{
	std::string label;
	int val;
	std::vector<int> seq;
	bool res;
};

std::istream& operator>>(std::istream& inputStream, Test& t)
{
	if (!inputStream)
	{
		return inputStream;
	}
	char ch1;
	char ch2;
	std::string label;
	int val;
	inputStream >> ch1 >> label >> val >> ch2;
	if (!inputStream || ch1 != '{' || ch2 != '{')
	{
		return inputStream;
	}
	std::vector<int> seq;
	bool res;
	int seqValue;
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
	t.label = label;
	t.val = val;
	t.seq = seq;
	t.res = res;
	return inputStream;
}

unsigned int test(std::ifstream& inputStream)
{
	unsigned errors = 0;
	for (Test t; inputStream >> t; )
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