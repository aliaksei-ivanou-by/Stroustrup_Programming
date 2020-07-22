#ifndef TASK_17_14_LINK_H
#define TASK_17_14_LINK_H

#ifndef TASK_17_14_STDAFX_H
#include "Task_17_14_stdafx.h"
#endif

struct God
{
	std::string name;
	std::string mythology;
	std::string vehicle;
	std::string weapon;
	God(const std::string& n, const std::string& m, const std::string& v, const std::string& w);
};

std::ostream& operator<<(std::ostream& os, const God& g);

class Link
{
public:
	God god;
	Link(God v, Link* s = nullptr);
	Link* insert(Link* n);
	Link* erase();
	Link* find(const std::string& s);
	const Link* find(const std::string& s) const;
	Link* advance(int n) const;
	Link* next() const;
private:
	Link* succ;
};

void print_all(Link* l);

#endif