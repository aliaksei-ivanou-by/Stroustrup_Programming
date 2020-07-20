#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
int main()
{
	std::vector<std::string> words;
	std::string disliked1="broccoli";
	std::string disliked2="pain";
	std::string disliked3="windows";
	for (std::string temp; std::cin>>temp;)
	{
		words.push_back(temp);
	}
	std::cout<<"Number of words : "<<words.size()<<".\n";
	std::sort(words.begin(), words.end());
	for (int i=0; i<words.size(); ++i)
	{
		if (i==0 || words[i-1]!=words[i])
			if (words[i]!=disliked1 && words[i]!=disliked2 && words[i]!=disliked3)
				std::cout<<words[i]<<"\n";
			else
				std::cout<<"BLEEP"<<"\n";
	}
	return 0;
}
