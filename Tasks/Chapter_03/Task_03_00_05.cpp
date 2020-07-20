// Считать и записать имя
#include "iostream"
int main()
{
	std::cout<<"Enter your name: \n";
	std::string name;
	std::cin>>name;
	std::cout<<"Enter the name of the recipient: \n";
	std::string recipient_name;
	std::cin>>recipient_name;
	std::cout<<"Enter the name of the friend: \n";
	std::string friend_name;
	std::cin>>friend_name;
	char friend_sex=0;
	std::cout<<"Choose the sex of the friend (m for male, f for female): \n";
	std::cin>>friend_sex;
	int age=0;
	std::cout<<"Enter the age of the friend: \n";
	std::cin>>age;
	std::cout<<"\nDear "<<recipient_name<<",\nHow are you? I'm good. I miss you.\n";
	std::cout<<"How long have you met "<<friend_name<< "?\n";
	if (friend_sex=='f')
		std::cout<<"If you see "<<friend_name<<" please ask her to call me.\n";
	if (friend_sex=='m')
		std::cout<<"If you see "<<friend_name<<" please ask him to call me.\n";

	if ((age>0)&&(age<110))
		std::cout<<"I heard you just celebrated your birthday and you turned "<<age<<" years old.\n";
	else
		std::cout<<"Are you kidding!\n";
	if (age<12)
		std::cout<<"Next year you will be "<<age+1<<" years old.\n";
	if (age==17)
		std::cout<<"Next year you will be able to vote.\n";
	if (age>70)
		std::cout<<"I hope you do not miss retirement.\n";

	std::cout<<"Sincerely yours,\n\n"<<name;
	return 0;
}
