#ifndef TASK_27_02_STDAFX_HPP
#include "Task_27_02_stdafx.hpp"
#endif

int main()
{
	struct List* names = create();
	struct Link* curr = 0;

	printf("\nInit names\n");
	print_names(names);

	printf("\npush_back - 3 names\n");
	push_back(names, (struct Link*)make_name("Norah"));
	push_back(names, (struct Link*)make_name("Annemarie"));
	push_back(names, (struct Link*)make_name("Kris"));
	print_names(names);

	printf("\npush_front - 3 names\n");
	push_front(names, (struct Link*)make_name("Alex")); // add "Alex"
	push_front(names, (struct Link*)make_name("Helen")); // add "Helen"
	push_front(names, (struct Link*)make_name("Max")); // add "Max"
	print_names(names);

	printf("\nerase element[3]\n");
	erase(names, advance(names->first, 3)); // remove element[3]
	print_names(names);

	printf("\ninsert Bill\n");
	insert(names, names->first->suc, (struct Link*)(make_name("Bill"))); // insert "Bill"
	print_names(names);

	destroy(names);
}