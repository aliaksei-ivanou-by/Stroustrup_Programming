#ifndef TASK_17_13_LINK_H
#define TASK_17_13_LINK_H

#ifndef TASK_17_13_STDAFX_H
#include "Task_17_13_stdafx.h"
#endif

struct God
{
	std::string name;
	std::string mythology;
	std::string vehicle;
	std::string weapon;
	God(const std::string& n, const std::string& m, const std::string& v, const std::string& w);
};

bool operator<(const God& g1, const God& g2);
std::ostream& operator<<(std::ostream& os, const God& g);

class Link
{
public:
	God god;
	Link(God v, Link* p = nullptr, Link* s = nullptr);
	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase();
	Link* find(const std::string& s);
	const Link* find(const std::string& s) const;
	Link* add_ordered(Link* n);
	Link* advance(int n) const;
	Link* next() const;
	Link* previous() const;
	Link* update();
private:
	Link* prev;
	Link* succ;
};

void print_all(Link* l);

#endif