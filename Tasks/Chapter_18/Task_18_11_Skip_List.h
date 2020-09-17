#ifndef TASK_18_11_SKIP_LIST_H
#define TASK_18_11_SKIP_LIST_H

#ifndef TASK_18_11_STDAFX_H
#include "Task_18_11_stdafx.h"
#endif

class Skip_List
{
public:
	Skip_List();
	void insert(int value);
	void remove(int value);
	void print();
private:
	class Node
	{
	public:
		Node(int value, int level);
		int value;
		std::vector<Node*> nodes;
	};
	const int level_max = 32;
	const int NIL = std::numeric_limits<int>::max();
	Node begin;
	Node end;
	int level;
	int get_level();
};
#endif