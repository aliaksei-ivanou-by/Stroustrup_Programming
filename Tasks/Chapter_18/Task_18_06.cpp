#include <iostream>
#include "std_lib_facilities.h"

std::string cat_dot(const std::string& s1, const std::string& s2, std::string delimeter = ".")
{
	return s1 + delimeter + s2;
}

int main()
try
{
	std::string s1 = "Niels";
	std::string s2 = "Bohr";

	std::cout << "s1 = " << s1 << '\n' <<
		"s2 = " << s2 << '\n';

	std::cout << cat_dot(s1, s2);

	std::cout << '\n';

	std::cout << cat_dot(s1, s2, " ");
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