#pragma once

#include <iostream>

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
struct CmpLess
{
	bool operator()(const T& leftValue, const T& rightValue)
	{
		return leftValue < rightValue;
	}
};

template<typename Iter, typename T, typename Compare>
bool myBinarySearch(Iter first, Iter last, const T& val, Compare cmp)
{
	if (first == last)
	{
		return false;
	}
	if (cmp(*(--last), val))
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
		if (!cmp(guess, val) && !cmp(val, guess))
		{
			return true;
		}
		if (cmp(val, guess))
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
	bool res;
};

template<typename T>
void get_seq(std::istream& inputStream, std::vector<T>& seq)
{
	seq.clear();
	if (!inputStream)
	{
		return;
	}
	char ch1;
	inputStream >> ch1;
	if (!inputStream || ch1 != '{')
	{
		return;
	}
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
}

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
	bool res;
	inputStream >> ch1 >> label >> val >> res >> ch2;
	if (!inputStream || ch1 != '{' || ch2 != '}')
	{
		return inputStream;
	}
	test.label = label;
	test.val = val;
	test.res = res;
	return inputStream;
}

template<typename T>
unsigned int test(std::ifstream& inputStreamSeq, std::ifstream& inputStreamTest)
{
	unsigned int errors = 0;
	for (Test<T> t; inputStreamTest >> t; )
	{
		inputStreamSeq.clear();
		inputStreamSeq.seekg(0);
		std::vector<T> seq;
		get_seq(inputStreamSeq, seq);
		std::vector<T> seqPre = seq;
		bool r = myBinarySearch(seq.begin(), seq.end(), t.val, CmpLess<T>());
		if (seqPre != seq)
		{
			std::cout << "failure: test " << t.label
				<< " the sequence has been modified\n";
			++errors;
		}
		if (r != t.res)
		{
			std::cout << "failure: test " << t.label <<
				" binary_search: " << seq.size() <<
				" elements, val = " << t.val <<
				" -> " << t.res << '\n';
			++errors;
		}
	}
	return errors;
}