#ifndef TASK_17_14_STDAFX_H
#include "Task_17_14_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	/*
	Singly linked list: we can move in one direction
	It is impossible to find out the address of the previous element.
	We can use singly linked list when it's important to track some iterations.
	*/
	
	Link* gods = new Link(God("Freia", "Norse", "Freia's vehicle", "Freia's weapon"));
	gods = gods->insert(new Link(God("Odin", "Norse", "Odin's vehicle", "Odin's weapon")));
	gods = gods->insert(new Link(God("Thor", "Norse", "Thor's vehicle", "Thor's weapon")));
	
	gods = gods->insert(new Link(God("Zeus", "Greek", "Zeus's vehicle", "Zeus's weapon ")));
	gods = gods->insert(new Link(God("Poseidon", "Greek", "Poseidon's vehicle", "Poseidon's weapon")));
	gods = gods->insert(new Link(God("Ares", "Greek", "Ares's vehicle", "Ares's weapon")));
	gods = gods->insert(new Link(God("Athena", "Greek", "Athena's vehicle", "Athena's weapon")));
	gods = gods->insert(new Link(God("Hera", "Greek", "Hera's vehicle", "Hera's weapon")));

	gods = gods->insert(new Link(God("Saturn", "Roman", "Saturn's vehicle", "Saturn's weapon")));
	gods = gods->insert(new Link(God("Ops", "Roman", "Ops's vehicle", "Ops's weapon")));
	gods = gods->insert(new Link(God("Jupiter", "Roman", "Jupiter's vehicle", "Jupiter's weapon")));
	gods = gods->insert(new Link(God("Mars", "Roman", "Mars's vehicle", "Mars's weapon")));
	gods = gods->insert(new Link(God("Venus", "Roman", "Venus's vehicle", "Venus's weapon")));
	gods = gods->insert(new Link(God("Minerva", "Roman", "Minerva's vehicle", "Minerva's weapon")));
	gods = gods->insert(new Link(God("Juno", "Roman", "Juno's vehicle", "Juno's weapon")));

	std::cout << "Not ordered All Gods :\n";
	print_all(gods);
	std::cout << "\n\n";

	delete gods;
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