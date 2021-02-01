#include <stdlib.h>
#include "Task_27_12_Table.hpp"

int main()
{
	char* letters[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
							"N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
	int* values[26] = { 0 };
	for (int i = 0; i < 26; ++i)
	{
		values[i] = i + 1;
	}

	struct Table* table = tableCreate();

	for (int i = 0; i < 26; ++i)
	{
		tableInsert(table, letters[i], values[i]);
	}
	tablePrint(table);

	tableInsert(table, "AA", 27);
	tableInsert(table, "BB", 28);
	tablePrint(table);

	tableRemove(table, "AA");
	tablePrint(table);

	tableRemove(table, "BB");
	tablePrint(table);

	tableDestroy(table);
}