#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

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

void init(struct List* lst)
{
	assert(lst);
	lst->first = lst->last = 0;
}

struct List* create()
{
	struct List* lst = (struct List*)malloc(sizeof(struct List));
	init(lst);
	return lst;
}

void clear(struct List* lst)
{
	assert(lst);
	{
		struct Link* curr = lst->first;
		while (curr)
		{
			struct Link* next = curr->suc;
			free(curr);
			curr = next;
		}
		lst->first = lst->last = 0;
	}
}

void destroy(struct List* lst)
{
	assert(lst);
	clear(lst);
	free(lst);
}

void push_back(struct List* lst, struct Link* p)
{
	assert(lst);
	{
		struct Link* last = lst->last;
		if (last)
		{
			last->suc = p;
			p->pre = last;
		}
		else
		{
			lst->first = p;
			p->pre = 0;
		}
		lst->last = p;
		p->suc = 0;
	}
}

void push_front(struct List* lst, struct Link* p)
{
	assert(lst);
	{
		struct Link* first = lst->first;
		if (first)
		{
			first->pre = p;
			p->suc = first;
		}
		else
		{
			lst->last = p;
			p->suc = 0;
		}
		lst->first = p;
		p->pre = 0;
	}
}

void insert(struct List* lst, struct Link* p, struct Link* q)
{
	assert(lst);
	{
		q->suc = p;
		if (p == lst->first)
		{
			q->pre = 0;
			lst->first = q;
		}
		else if (p == lst->last)
		{
			if (p->pre)
			{
				q->pre = p->pre;
				p->pre->suc = q;
			}
			else
			{
				q->suc = 0;
			}
		}
		else
		{
			q->pre = p->pre;
			p->pre->suc = q;
		}
		p->pre = q;
	}
}

struct Link* erase(struct List* lst, struct Link* p)
{
	assert(lst);
	if (p == 0)
	{
		return 0;
	}
	if (p == lst->first)
	{
		if (p->suc)
		{
			lst->first = p->suc;
			p->suc->pre = 0;
			return p->suc;
		}
		else
		{
			lst->first = lst->last = 0;
			return 0;
		}
	}
	else
	{
		if (p == lst->last)
		{
			if (p->pre)
			{
				lst->last = p->pre;
				p->pre->suc = 0;
			}
			else
			{
				lst->first = lst->last = 0;
				return 0;
			}
		}
		else
		{
			p->suc->pre = p->pre;
			p->pre->suc = p->suc;
			return p->suc;
		}
	}
}

struct Link* advance(struct Link* p, int n)
{
	struct Link* curr = p;
	if (n > 0)
	{
		while (n--)
		{
			curr = curr->suc;
		}
	}
	else
	{
		while (n++)
		{
			curr = curr->pre;
		}
	}
	return curr;
}

struct Name
{
	struct Link lnk;
	char* n;
};

struct Name* make_name(char* n)
{
	struct Name* p = (struct Name*)malloc(sizeof(struct Name));
	p->n = n;
	return p;
}

void print_names(struct List* lst)
{
	assert(lst);
	{
		struct Link* curr = lst->first;
		char* n = 0;
		while (curr)
		{
			n = ((struct Name*)curr)->n;
			printf("Name: %s\n", n);
			curr = curr->suc;
		}
	}
}