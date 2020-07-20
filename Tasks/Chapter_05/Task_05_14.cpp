#include "iostream"
#include "vector"
int main()
{
	std::vector<int> monday;
	std::vector<int> tuesday;
	std::vector<int> wednesday;
	std::vector<int> thursday;
	std::vector<int> friday;
	std::vector<int> saturday;
	std::vector<int> sunday;
	std::string day="";
	int key=1, sum=0, number=0;
	int exception=0;
	while(key==1)
	{
		std::cout<<"Enter day of week : \n";
		std::cin>>day;
		std::cout<<"Enter int number\n";
		std::cin>>number;
		if (day=="monday" || day=="mon")
			monday.push_back(number);
		else
			if (day=="tuesday" || day=="tu")
				tuesday.push_back(number);
			else
				if (day=="wednesday" || day=="we")
					wednesday.push_back(number);
				else
					if (day=="thursday" || day=="th")
						thursday.push_back(number);
					else
						if (day=="friday" || day=="fr")
							friday.push_back(number);
						else
							if (day=="saturday" || day=="sa")
								saturday.push_back(number);
							else
								if (day=="sunday" || day=="su")
									sunday.push_back(number);
								else
								{
									std::cout<<"Sorry, unknown day.\n";
									exception++;
								}
		std::cout<<"Please, enter '1' to continue or enter '0' to exit.\n";
		std::cin>>key;
	}
	std::cout<<"\nMonday: ";
	if (monday.size()>0)
		for (int i : monday)
			std::cout<<i<<" ";
	else
		std::cout<<"No numbers";
	sum=0;
	for (int i : monday)
		sum+=i;
	std::cout<<"\nSum : "<<sum<<"\n";

	std::cout<<"\nTuesday: ";
	if (tuesday.size()>0)
		for (int i : tuesday)
			std::cout<<i<<" ";
	else
		std::cout<<"No numbers";
	sum=0;
	for (int i : tuesday)
		sum+=i;
	std::cout<<"\nSum : "<<sum<<"\n";

	std::cout<<"\nWednesday: ";
	if (wednesday.size()>0)
		for (int i : wednesday)
			std::cout<<i<<" ";
	else
		std::cout<<"No numbers";
	sum=0;
	for (int i : wednesday)
		sum+=i;
	std::cout<<"\nSum : "<<sum<<"\n";

	std::cout<<"\nThursday: ";
	if (thursday.size()>0)
		for (int i : thursday)
			std::cout<<i<<" ";
	else
		std::cout<<"No numbers";
	sum=0;
	for (int i : thursday)
		sum+=i;
	std::cout<<"\nSum : "<<sum<<"\n";

	std::cout<<"\nFriday: ";
	if (friday.size()>0)
		for (int i : friday)
			std::cout<<i<<" ";
	else
		std::cout<<"No numbers";
	sum=0;
		for (int i : friday)
	sum+=i;
	std::cout<<"\nSum : "<<sum<<"\n";

	std::cout<<"\nSaturday: ";
	if (saturday.size()>0)
		for (int i : saturday)
			std::cout<<i<<" ";
	else
		std::cout<<"No numbers";
	sum=0;
	for (int i : saturday)
		sum+=i;
	std::cout<<"\nSum : "<<sum<<"\n";

	std::cout<<"\nSunday: ";
	if (sunday.size()>0)
		for (int i : sunday)
			std::cout<<i<<" ";
	else
		std::cout<<"No numbers";
	sum=0;
	for (int i : sunday)
		sum+=i;
	std::cout<<"\nSum : "<<sum<<"\n";

	std::cout<<"\nThe number of raw values : "<<exception<<"\n";
	return 0;
}
