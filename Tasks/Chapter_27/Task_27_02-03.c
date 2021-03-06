﻿#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Task_27_List.hpp"

int main()
{
	struct List* names = create();
	struct Link* curr = 0;

	printf("\nInit names\n");
	print_names(names);

	printf("\npush_back - 3 names\n");
	push_back(names, (struct Link*)make_name("Norah")); // add 'Norah'
	push_back_name(names, "Annemarie"); // add 'Annemarie'
	push_back_name(names, "Kris"); // add 'Kris'
	print_names(names);

	printf("\npush_front - 3 names\n");
	push_front(names, (struct Link*)make_name("Alex")); // add "Alex"
	push_front_name(names, "Helen"); // add "Helen"
	push_front_name(names, "Max"); // add "Max"
	print_names(names);

	printf("\nerase element[3]\n");
	erase(names, advance(names->first, 3)); // remove element[3]
	print_names(names);

	printf("\ninsert Bill & Jack\n");
	insert(names, names->first->next, (struct Link*)(make_name("Bill"))); // insert "Bill"
	insert_name(names, names->first->next, "Jack"); // insert "Jack"
	print_names(names);

	destroy(names);
}