#ifndef TASK_15_00_02_PERSON_H
#define TASK_15_00_02_PERSON_H

#ifndef TASK_15_00_02_STDAFX_H
#include "Task_15_00_02_stdafx.h"
#endif

class Person
{
public:
	Person();
	Person(std::string first_name, std::string second_name, int age);
	std::string get_first_name() const;
	std::string get_second_name() const;
	void set_first_name(std::string fn);
	void set_second_name(std::string sn);
	int get_age() const;
	void set_age(int a);
private:
	std::string first_name;
	std::string second_name;
	int age;
	void validate_first_name();
	void validate_second_name();
	void validate_age();
};

ostream& operator<<(ostream& o_stream, const Person& person);
istream& operator>>(istream& i_stream, Person& person);

#endif