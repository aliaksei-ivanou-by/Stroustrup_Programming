#ifndef TASK_17_13_STDAFX_H
#include "Task_17_13_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
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

	Link* gods_norse = nullptr;
	gods_norse = gods_norse->add_ordered(gods->find("Freia")->update());
	gods_norse = gods_norse->add_ordered(gods->find("Odin")->update());
	gods_norse = gods_norse->add_ordered(gods->find("Thor")->update());

	std::cout << "Ordered Norse Gods :\n";
	print_all(gods_norse);
	std::cout << "\n\n";

	Link* gods_greek = nullptr;
	gods_greek = gods_greek->add_ordered(gods->find("Zeus")->update());
	gods_greek = gods_greek->add_ordered(gods->find("Poseidon")->update());
	gods_greek = gods_greek->add_ordered(gods->find("Ares")->update());
	gods_greek = gods_greek->add_ordered(gods->find("Athena")->update());
	gods_greek = gods_greek->add_ordered(gods->find("Hera")->update());

	std::cout << "Ordered Greek Gods :\n";
	print_all(gods_greek);
	std::cout << "\n\n";

	Link* gods_roman = nullptr;
	gods_roman = gods_roman->add_ordered(gods->find("Saturn")->update());
	gods_roman = gods_roman->add_ordered(gods->find("Ops")->update());
	gods_roman = gods_roman->add_ordered(gods->find("Jupiter")->update());
	gods_roman = gods_roman->add_ordered(gods->find("Mars")->update());
	gods_roman = gods_roman->add_ordered(gods->find("Venus")->update());
	gods_roman = gods_roman->add_ordered(gods->find("Minerva")->update());
	gods_roman = gods_roman->add_ordered(gods->find("Juno")->update());

	std::cout << "Ordered Roman Gods :\n";
	print_all(gods_roman);
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