#ifndef TASK_17_11_LINK_H
#define TASK_17_11_LINK_H

#ifndef TASK_17_11_STDAFX_H
#include "Task_17_11_stdafx.h"
#endif

class Link
{
public:
	std::string value;
	Link(const std::string& v, Link* p = nullptr, Link* s = nullptr);
	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase();
	Link* find(const std::string& s);
	const Link* find(const std::string& s) const;
	Link* advance(int n) const;
	Link* next() const;
	Link* previous() const;
private:
	Link* prev;
	Link* succ;
};

void print_all(Link* p);

#endif