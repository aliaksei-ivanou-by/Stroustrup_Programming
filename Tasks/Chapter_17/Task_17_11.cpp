#ifndef TASK_17_11_STDAFX_H
#include "Task_17_11_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	Link* norse_gods = new Link("Thor");
	norse_gods = norse_gods->insert(new Link("Odin"));
	norse_gods = norse_gods->insert(new Link("Zeus"));
	norse_gods = norse_gods->insert(new Link("Freia"));

	Link* greek_gods = new Link("Hera");
	greek_gods = greek_gods->insert(new Link("Athena"));
	greek_gods = greek_gods->insert(new Link("Mars"));
	greek_gods = greek_gods->insert(new Link("Poseidon"));

	Link* p = greek_gods->find("Mars");
	if (p)
	{
		p->value = "Ares";
	}

	Link* p2 = norse_gods->find("Zeus");
	if (p2)
	{
		if (p2 == norse_gods)
		{
			norse_gods = p2->next();
		}
		p2->erase();
		greek_gods = greek_gods->insert(p2);
	}

	print_all(norse_gods);
	std::cout << '\n';

	print_all(greek_gods);
	std::cout << '\n';

	Link* n1 = greek_gods->advance(5);
	print_all(n1);
}
catch (const std::exception& e)
{
	std::cout << "Exception occured: " << e.what() << '\n';
	return 1;
}
catch (...)
{
	return 2;
}