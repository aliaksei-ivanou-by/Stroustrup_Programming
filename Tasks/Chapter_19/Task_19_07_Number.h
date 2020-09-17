#ifndef TASK_19_07_NUMBER_H
#define TASK_19_07_NUMBER_H

#ifndef TASK_19_07_STDAFX_H
#include "Task_19_07_stdafx.h"
#endif

template<typename T>
class Number
{
private:
	T value;
public:
	Number<T>(T i) :
		value{ i }
	{}
	Number<T>& operator=(const T number)
	{
		value = number;
		return *this;
	}
	T get() const
	{
		return value;
	}
	Number<T> operator= (Number<T> number)
	{
		std::swap(value, number.value);
		return *this;
	}
	friend Number<T> operator+(const Number<T>& numberLeft, const Number<T>& numberRight)
	{
		return Number<T>(numberLeft.get() + numberRight.get());
	}
	friend Number<T> operator-(const Number<T>& numberLeft, const Number<T>& numberRight)
	{
		return Number<T>(numberLeft.get() - numberRight.get());
	}
	friend Number<T> operator*(const Number<T>& numberLeft, const Number<T>& numberRight)
	{
		return Number<T>(numberLeft.get() * numberRight.get());
	}
	friend Number<T> operator/(const Number<T>& numberLeft, const Number<T>& numberRight)
	{
		if (0 == numberRight.get())
		{
			throw std::runtime_error("Division by zero");
		}
		return Number<T>(numberLeft.get() / numberRight.get());
	}
	Number<T> operator% (Number<T>& numberRight)
	{
		return Number<T>(value % numberRight.value);
	}
	friend std::ostream& operator<<(std::ostream& outputStream, const Number<T>& number)
	{
		return outputStream << number.get();
	}
	friend std::istream& operator>>(std::istream& inputStream, Number<T>& number)
	{
		T value = 0;
		inputStream >> value;
		number = value;
		return inputStream;
	}
};

#endif