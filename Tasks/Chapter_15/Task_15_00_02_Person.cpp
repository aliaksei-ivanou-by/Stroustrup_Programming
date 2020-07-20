#ifndef TASK_15_00_02_PERSON_H
#include "Task_15_00_02_stdafx.h"
#include "Task_15_00_02_Person.h"
#endif

Person::Person()
	: first_name{ "" }, second_name{ "" }, age{ 0 }
{
}

Person::Person(std::string fn, std::string sn, int a)
{
	set_first_name(fn);
	set_second_name(sn);
	set_age(a);
}

std::string Person::get_first_name() const
{
	return first_name;
}

std::string Person::get_second_name() const
{
	return second_name;
}

void Person::set_first_name(std::string fn)
{
	this->first_name = fn;
	validate_first_name();
}

void Person::set_second_name(std::string sn)
{
	this->second_name = sn;
	validate_second_name();
}

int Person::get_age() const
{
	return age;
}

void Person::set_age(int a)
{
	this->age = a;
	validate_age();
}

void Person::validate_first_name()
{
	const std::string chars = ";:\"'[]*&^%$#@!";
	for (int i = 0; i < first_name.size(); ++i)
	{
		for (int j = 0; j < chars.size(); ++j)
		{
			if (first_name[i] == chars[j])
			{
				error("Illegal char in first name : ", std::string(1, first_name[i]));
			}
		}
	}
}

void Person::validate_second_name()
{
	const std::string chars = ";:\"'[]*&^%$#@!";
	for (int i = 0; i < second_name.size(); ++i)
	{
		for (int j = 0; j < chars.size(); ++j)
		{
			if (second_name[i] == chars[j])
			{
				error("Illegal char in second name : ", std::string(1, second_name[i]));
			}
		}
	}
}

void Person::validate_age()
{
	if (age < 0 || age >= 150)
	{
		error("Age mush be in range [0, 150)");
	}
}

ostream& operator<<(ostream& os, const Person& p)
{
	return os << "Name : " << p.get_first_name() <<
		' ' << p.get_second_name() <<
		"\tAge : " << p.get_age() << "\n";
}

istream& operator>>(istream& is, Person& p)
{
	std::string first_name;
	std::string second_name;
	int age;
	is >> first_name >> second_name >> age;
	if (!is)
	{
		return is;
	}
	p = Person(first_name, second_name, age);
	return is;
}
