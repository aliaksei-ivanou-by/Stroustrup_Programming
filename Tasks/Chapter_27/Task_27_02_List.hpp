#ifndef TASK_27_02_LIST_HPP
#define TASK_27_02_LIST_HPP

#ifndef TASK_27_02_STDAFX_HPP
#include "Task_27_02_stdafx.hpp"
#endif

struct Link
{
	struct Link* pre;
	struct Link* suc;
};

struct List
{
	struct Link* first;
	struct Link* last;
};

void init(struct List* lst);
struct List* create();

void clear(struct List* lst);
void destroy(struct List* lst);

void push_back(struct List* lst, struct Link* p);
void push_front(struct List* lst, struct Link* p);

void insert(struct List* lst, struct Link* p, struct Link* q);
struct Link* erase(struct List* lst, struct Link* p);
struct Link* advance(struct Link* p, int n);

struct Name
{
	struct Link lnk;
	char* n;
};

struct Name* make_name(char* n);
void print_names(struct List* lst);

#endif