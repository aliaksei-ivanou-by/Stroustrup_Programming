#include "iostream"
#include "vector"
int main()
{
	std::vector<std::string> arr;
	std::cout<<"Please, choose variant 1 for default and 2 for input answers : \n";
	int n;
	std::cin>>n;
	switch(n)
	{
		case (1):
			arr={"rock", "rock", "scissors", "rock", "paper", "rock", "paper", "scissors", "paper"};
			break;
		case (2):
			std::cout<<"For exit, please enter CTRL+Z.\n";
			for (std::string temp; std::cin>>temp;)
			{
				arr.push_back(temp);
			}
			break;
	}
	// game
	std::string x;
	for (int i=0; i<arr.size();i++)
	{
		std::cout<<"Rock ... Scissors ... Paper ... One ... Two ... Three\n";
		std::cout<<"Your variant : ";
		std::cin>>x;
		std::cout<<"Computer variant : ";
		std::cout<<arr[i];
		std::cout<<"\n";
		if (x==arr[i]) // 1
			std::cout<<"Draw.\n";
		if (x=="paper" && arr[i]=="rock") // 2
			std::cout<<"You win (paper wraps rock).\n";
		if (x=="rock" && arr[i]=="paper") // 3
			std::cout<<"Computer win (paper wraps rock).\n";
		if (x=="rock" && arr[i]=="scissors") // 4
			std::cout<<"You win (the rock blunts or breaks the scissors).\n";
		if (x=="scissors" && arr[i]=="rock") // 5
			std::cout<<"Computer win (the rock blunts or breaks the scissors).\n";
		if (x=="scissors" && arr[i]=="paper") // 6
			std::cout<<"You win (scissors cut the paper).\n";
		if (x=="paper" && arr[i]=="scissors") // 7
			std::cout<<"You win (scissors cut the paper).\n";
		std::cout<<"\n";
	}
	std::cout<<"Game over.\n";
	return 0;
}
