#ifndef TASK_19_04_GOD_H
#define TASK_19_04_GOD_H

#ifndef TASK_19_04_STDAFX_H
#include "Task_19_04_stdafx.h"
#endif

struct God
{
	std::string name;
	std::string mythology;
	std::string vehicle;
	std::string weapon;
	God(const std::string& n = "", const std::string& m = "", const std::string& v = "", const std::string& w = ""):
		name{ n },
		mythology{ m },
		vehicle{ v },
		weapon{ w }
	{}
	friend bool operator<(const God& godLeft, const God& godRight)
	{
		return godLeft.name < godRight.name;
	}
	friend bool operator>(const God& godLeft, const God& godRight)
	{
		return operator<(godRight, godLeft);
	}
	friend std::ostream& operator<<(std::ostream& outputStream, const God& g)
	{
		return outputStream << "{ " <<
			g.name << ", " <<
			g.mythology << ", " <<
			g.vehicle << ", " <<
			g.weapon << " }\n";
	}
};

#endif