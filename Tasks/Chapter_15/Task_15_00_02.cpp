#ifndef TASK_15_00_02_STDAFX_H
#include "Task_15_00_02_stdafx.h"
#endif

int main(int argc, char** argv)
try
{
	/*std::cout << "Person 1\n";
	Person p1("Goofy", 63);
	std::cout << "Name : " << p1.get_name() <<
		"\tAge : " << p1.get_age() << "\n";
	std::cout << "Person 2\n";
	Person p2;
	p2.set_name("John");
	p2.set_age(54);
	std::cout << p2; */
	std::cout << "Vector of Person\n";
	vector<Person> persons;
	Person pp1;
	std::cin >> pp1;
	persons.push_back(pp1);
	Person pp2;
	std::cin >> pp2;
	persons.push_back(pp2);
	for (auto person : persons)
	{
		std::cout << person;
	}
	return 0;
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