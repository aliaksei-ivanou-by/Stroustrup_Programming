#include <stdlib.h>
#include "Task_27_12_Table.hpp"

int main()
{
	char* letters[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K" };
	int values[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int s = 11;

	table = tableCreate(s);

	for (int i = 0; i < s; ++i)
	{
		tableInsert(table, letters[i], values[i]);
	}

	tablePrint();

	int element = 5;
	struct Table* t = tableFind(table, letters[element]);
	if (t != 0)
	{
		printf("Element '%s' in table is: '%s' - %d\n\n", letters[element], t->name, t->value);
	}
	else
	{
		printf("No element '%s' in table\n\n", letters[element]);
	}

	tableRemove(table, letters[5]);

	tablePrint();

	t = tableFind(table, letters[element]);
	if (t != 0)
	{
		printf("Element '%s' in table is: '%s' - %d\n\n", letters[element], t->name, t->value);
	}
	else
	{
		printf("No element '%s' in table\n\n", letters[element]);
	}

	tableInsert(table, 11, "M");
}