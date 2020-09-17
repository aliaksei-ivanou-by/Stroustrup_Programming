#ifndef TASK_19_03_PAIR_H
#define TASK_19_03_PAIR_H

#ifndef TASK_19_03_STDAFX_H
#include "Task_19_03_stdafx.h"
#endif

template<typename T1, typename T2>
class Pair
{
private:
	T1 t1;
	T2 t2;
public:
	Pair(T1 t1, T2 t2):
		t1{ t1 },
		t2{ t2 }
	{}
	T1 getFirst() const
	{
		return t1;
	}
	T2 getSecond() const
	{
		return t2;
	}
	void setFirst(T1 t1ToUpdate)
	{
		t1 = t1ToUpdate;
	}
	void setFirst(T2 t2ToUpdate)
	{
		t2 = t2ToUpdate;
	}
	friend std::ostream& operator<< (std::ostream& outputStream, const Pair<T1, T2>& pair)
	{
		outputStream << pair.getFirst() << '\t' << pair.getSecond() << "\n";
		return outputStream;
	}
};

#endif