#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct Link
{
	struct Link* prev;
	struct Link* next;
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
			struct Link* next = curr->next;
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
	assert(p);
	{
		struct Link* last = lst->last;
		if (last)
		{
			last->next = p;
			p->prev = last;
		}
		else
		{
			lst->first = p;
			p->prev = 0;
		}
		lst->last = p;
		p->next = 0;
	}
}

void push_front(struct List* lst, struct Link* p)
{
	assert(lst);
	assert(p);
	{
		struct Link* first = lst->first;
		if (first)
		{
			first->prev = p;
			p->next = first;
		}
		else
		{
			lst->last = p;
			p->next = 0;
		}
		lst->first = p;
		p->prev = 0;
	}
}

void insert(struct List* lst, struct Link* p, struct Link* q)
{
	assert(lst);
	assert(p);
	assert(q);
	{
		q->next = p;
		if (p == lst->first)
		{
			q->prev = 0;
			lst->first = q;
		}
		else if (p == lst->last)
		{
			if (p->prev)
			{
				q->prev = p->prev;
				p->prev->next = q;
			}
			else
			{
				q->next = 0;
			}
		}
		else
		{
			q->prev = p->prev;
			p->prev->next = q;
		}
		p->prev = q;
	}
}

struct Link* erase(struct List* lst, struct Link* p)
{
	assert(lst);
	assert(p);
	if (p == 0)
	{
		return 0;
	}
	if (p == lst->first)
	{
		if (p->next)
		{
			lst->first = p->next;
			p->next->prev = 0;
			return p->next;
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
			if (p->prev)
			{
				lst->last = p->prev;
				p->prev->next = 0;
			}
			else
			{
				lst->first = lst->last = 0;
				return 0;
			}
		}
		else
		{
			p->next->prev = p->prev;
			p->prev->next = p->next;
			return p->next;
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
			curr = curr->next;
		}
	}
	else
	{
		while (n++)
		{
			curr = curr->prev;
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
			curr = curr->next;
		}
	}
}

void push_back_name(struct List* list, char* name)
{
	return push_back(list, (struct Link*)make_name(name));
}

void push_front_name(struct List* list, char* name)
{
	return push_front(list, (struct List*)make_name(name));
}

void insert_name(struct List* list, struct Link* p, char* name)
{
	return insert(list, p, (struct List*)make_name(name));
}