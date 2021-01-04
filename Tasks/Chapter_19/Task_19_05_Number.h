#ifndef TASK_19_05_NUMBER_H
#define TASK_19_05_NUMBER_H

#ifndef TASK_19_05_STDAFX_H
#include "Task_19_05_stdafx.h"
#endif

class Number
{
private:
	int value;
public:
	Number(int i) :
		value{ i }
	{}
	Number& operator=(const int number)
	{
		value = number;
		return *this;
	}
	int get() const
	{
		return value;
	}
	friend Number operator+(const Number& numberLeft, const Number& numberRight)
	{
		return Number(numberLeft.get() + numberRight.get());
	}
	friend Number operator-(const Number& numberLeft, const Number& numberRight)
	{
		return Number(numberLeft.get() - numberRight.get());
	}
	friend Number operator*(const Number& numberLeft, const Number& numberRight)
	{
		return Number(numberLeft.get() * numberRight.get());
	}
	friend Number operator/(const Number& numberLeft, const Number& numberRight)
	{
		if (0 == numberRight.get())
		{
			throw std::runtime_error("Division by zero");
		}
		return Number(numberLeft.get() / numberRight.get());
	}
	Number operator%(Number& numberRight)
	{
		return Number(value % numberRight.value);
	}
	friend std::ostream& operator<<(std::ostream& outputStream, const Number& number)
	{
		return outputStream << number.get();
	}
	friend std::istream& operator>>(std::istream& inputStream, Number& number)
	{
		int value = 0;
		inputStream >> value;
		number = value;
		return inputStream;
	}
};

#endif