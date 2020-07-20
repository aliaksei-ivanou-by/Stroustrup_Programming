#include "iostream"
#include "Task_09_08_Lib.h"

int main()
{
	Lib::Patron person(1, "Aliaksei Ivanou", 5);
	if (Lib::owes_fees(person))
		std::cout<<"Person have to pay!\n";
	else
		std::cout<<"Person haven't to pay!\n";
	person.see_fees(0);
	if (Lib::owes_fees(person))
		std::cout<<"Person have to pay!\n";
	else
		std::cout<<"Person haven't to pay!\n";
	return 0;
}
