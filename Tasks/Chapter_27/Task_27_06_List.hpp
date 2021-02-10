#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

#define LIST_SIZE 10

struct Link
{
	int prev;
	int next;
	char* p;
};

struct Link* make_name(char* n)
{
	struct Link* p = (struct Link*)malloc(sizeof(struct Link));
	p->p = n;
	return p;
}

struct List
{
	int first;
	int last;
	struct Link links[LIST_SIZE];
};

void init(struct List* lst)
{
	assert(lst);
	// array element numbering. '-1' - absence in the array
	// first element in the array has next element '-1' and previous element '-1'
	// last element in the array has next element '-1'
	lst->first = -1;
	lst->last = -1;
}

struct List* create()
{
	struct List* lst = (struct List*)malloc(sizeof(struct List));
	init(lst);
	return lst;
}

void destroy(struct List* lst)
{
	assert(lst);
	free(lst);
}

void list_move_left(struct List* lst, int i)
{
	while (i < lst->last + 1)
	{
		lst->links[i - 1] = lst->links[i];
		--(lst->links[i - 1].prev);
		--(lst->links[i - 1].next);
		++i;
	}
	lst->links[i - 2].next = -1;
	lst->links[i - 1].next = INT_MIN;
	lst->links[i - 1].prev = INT_MIN;
	lst->links[i - 1].p = "";
	--(lst->last);
}

void list_move_right(struct List* lst, int i)
{
	int j = lst->last;
	while (j > i - 1)
	{
		lst->links[j + 1] = lst->links[j];
		++(lst->links[j + 1].prev);
		if (lst->links[j].next == -1) // last
		{
			lst->links[j + 1].next = -1;
		}
		else // not last
		{
			lst->links[j + 1].next = lst->links[j].next + 1;
		}
		--j;
	}
	++(lst->last);
}

void push_back(struct List* lst, struct Link* p)
{
	assert(lst);
	assert(p);
	{
		if (lst->first == -1) // empty array
		{
			++(lst->first);
			p->prev = -1;
		}
		else
		{
			lst->links[lst->last].next = lst->last + 1;
			p->prev = lst->last;
		}
		++(lst->last);
		p->next = -1;
		lst->links[lst->last] = *p;
		free(p);
	}
}

void push_front(struct List* lst, struct Link* p)
{
	if (lst->first == -1) // empty array
	{
		push_back(lst, p);
	}
	else
	{
		list_move_right(lst, 0);
		p->prev = -1;
		p->next = 1;
		lst->links[lst->first] = *p;
		free(p);
	}
}

void insert(struct List* lst, struct Link* p, struct Link* q)
{
	assert(lst);
	assert(p);
	assert(q);
	{
		if (p == &lst->links[lst->first]) // empty array
		{
			push_front(lst, q);
		}
		else
		{
			list_move_right(lst, lst->links[p->prev].next);
			q->prev = p->prev;
			q->next = p->prev + 2;
			lst->links[p->prev + 1] = *q;
		}
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
	if (p == &lst->links[lst->last] && p == &lst->links[lst->first])
	{
		lst->first = -1;
		--(lst->last);
		return &lst->links[lst->last + 1];
	}
	if (p == &lst->links[lst->last] && p != &lst->links[lst->first])
	{
		lst->links[p->prev].next = -1;
		--(lst->last);
		return &lst->links[lst->last + 1];
	}
	if (p != &lst->links[lst->last] && p != &lst->links[lst->first])
	{
		int i = p->prev + 1;
		list_move_left(lst, i + 1);
		return &lst->links[i];
	}
}

struct Link* advance(struct List* lst, struct Link* p, int n)
{
	assert(lst);
	assert(p);
	int i = p - &lst->links[lst->first];
	i += n;
	return &lst->links[i];
}

void print_names(struct List* lst)
{
	assert(lst);
	for (auto i = 0; i < lst->last + 1; ++i)
	{
		printf("Name %d: %s\n", i + 1, lst->links[i].p);
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