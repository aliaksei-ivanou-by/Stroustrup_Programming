#pragma once
#include <stdlib.h>

struct Table
{
	const char* name;
	int value;
};

int cap;
int sz;
struct Table* table;

int size()
{
	return sz;
}

void set_size(int sz_new)
{
	sz = sz_new;
}

int capacity()
{
	return cap;
}

void set_capacity(int cap_new)
{
	cap = cap_new;
}

int cmp_find(const char* name, const struct Table* rightTable)
{
	return strcmp(name, rightTable->name);
}

int cmp_sort(const struct Table* leftTable, const struct Table* rightTable)
{
	return strcmp(leftTable->name, rightTable->name);
}

struct Table* tableCreate(int s)
{
	set_capacity(s);
	struct Table* p = 0;
	p = (struct Table*)malloc(sizeof(struct Table), capacity);
	if (!p)
	{
		perror("tableCreate :: bad allocation");
		exit(1);
	}
	return p;
}

struct Table* tableFind(struct Table* table, const char* name)
{
	return (struct Table*)bsearch(name, table, size(), sizeof(struct Table), cmp_find);
}

void tableInsert(struct Table* table, const char* name, int value)
{
	table[size()].name = name;
	table[size()].value = value;
	set_size(size() + 1);
	qsort(table, size(), sizeof(struct Table), cmp_sort);
}

void tableRemove(struct Table* table, const char* name)
{
	struct Table* find = tableFind(table, name);
	if (find)
	{
		for (int i = find - table; i < size() - 1; ++i)
		{
			table[i] = table[i + 1];
		}
		set_size(size() - 1);
	}
	else
	{
		perror("tableRemove :: no name in table");
	}
}

void tablePrint()
{
	printf("\nTable:\n");
	int n = size();
	for (int i = 0; i < n; ++i)
	{
		printf("%s\t%d\n", table[i].name, table[i].value);
	}
	printf("Table Size = %d, Capacity = %d\n\n", size(), capacity());
}
