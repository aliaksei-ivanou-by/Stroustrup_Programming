#pragma once
#include <stdlib.h>

struct Pair
{
	const char* name;
	int value;
};

struct Pair* pair(const char* name, int value)
{
	struct Pair* p = (struct Pair*)malloc(sizeof(struct Pair));
	p->name = name;
	p->value = value;
	return p;
}

struct Table
{
	struct Pair* elem;
	int sz;
	int cap;
};

struct Table* tableCreate()
{
	struct Table* table = (struct Table*)malloc(sizeof(struct Table));
	table->elem = NULL;
	table->sz = 0;
	table->cap = 0;
	return table;
}

void tableDestroy(struct Table* table)
{
	free(table);
}

void tableResize(struct Table* table)
{
	if (table->cap == 0)
	{
		table->elem = (struct Pair*)malloc(sizeof(struct Pair) * 2);
		table->cap = 2;
		return;
	}
	else
	{
		if (table->sz == table->cap)
		{
			table->elem = (struct Pair*)realloc(table->elem, sizeof(struct Pair) * table->cap * 2);
			table->cap *= 2;
			return;
		}
	}
}

void tableInsert(struct Table* table, const char* name, int value)
{
	tableResize(table);
	table->elem[table->sz] = *pair(name, value);
	++table->sz;
}

void tablePrint(struct Table* table)
{
	printf("Table:\n");
	for (int i = 0; i < table->sz; ++i)
	{
		printf("\t%d:\t%s\t%d\n", i, table->elem[i].name, table->elem[i].value);
	}
	printf("Size = %d. Capacity = %d\n", table->sz, table->cap);
}

struct Pair* tableFind(struct Table* table, const char* name)
{
	for (struct Pair* i = table->elem; i != table->elem + table->sz; ++i)
	{
		if (strcmp(name, i->name) == 0)
		{
			return i;
		}
	}
	return NULL;
}

void tableRemove(struct Table* table, const char* name)
{
	struct Pair* temp = tableFind(table, name);
	if (!temp)
	{
		printf("Can't find name '%s' in table", name);
		return;
	}
	while (temp != table->elem + table->sz - 1)
	{
		temp->name = (temp + 1)->name;
		temp->value = (temp + 1)->value;
		++temp;
	}
	--table->sz;
}