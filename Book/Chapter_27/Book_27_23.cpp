void init(struct List* lst);
struct List* create();
void clear(struct List* lst);
void destroy(struct List* lst);
void push_back(struct List* lst, struct Link* p);
void push_front(struct List* lst, struct Link* p);
void insert(struct List* lst, struct Link* p, struct Link* q);
struct Link* erase(struct List* lst, struct Link* p);
struct Link* advance(struct Link* p, int n);

struct List
{
	struct Link* first;
	struct Link* last;
};

struct Link
{
	struct Link* pre;
	struct Link* suc;
};

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
			p-pre = last;
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

int main()
{
	int count = 0;
	struct List = names;
	struct List* curr;
	
	push_back(&names, (struct Link*)make_name("Norah"));
	push_back(&names, (struct Link*)make_name("Annemarie"));
	push_back(&names, (struct Link*)make_name("Kris"));
	
	erase(&names, advance(names.first, 1));
	curr = names.first;
	for (; curr != 0; curr = curr->suc)
	{
		count++;
		printf(element %d: %s\n", count, ((struct Name*)curr)->n);
	}
}