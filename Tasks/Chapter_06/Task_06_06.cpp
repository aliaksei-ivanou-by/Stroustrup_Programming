#include "iostream"

bool article(std::string words)
{
	if (words=="the")
		return true;
	else
		return false;
}

bool verb(std::string words)
{
	if (words=="rules" || words=="fly" || words=="swim")
		return true;
	else
		return false;
}

bool noun(std::string words)
{
	if (words=="birds" || words=="fish" || words=="c++")
		return true;
	else
		return false;
}

bool conjunction(std::string words)
{
	if (words=="and" || words=="but" || words=="or")
		return true;
	else
		return false;
}

bool sentence()
{
	std::string w1;
	std::string w2;
	std::string w3;
	std::string w4;

	std::cin>>w1;
	if (!noun(w1) && !article(w1))
		return false;

	std::cin>>w2;
	if (noun(w1) && !verb(w2))
		return false;
	if (article(w1) && !noun(w2))
		return false;

	std::cin>>w3;
	if (noun(w1) && verb(w2) && (w3=="."))
		return true;
	if (verb(w2) && !conjunction(w3))
		return false;
	if (noun(w2) && !verb(w3))
		return false;
	if (conjunction(w3))
		return sentence();

	std::cin>>w4;
	if (article(w1) && noun(w2) && verb(w3) && (w4=="."))
		return true;
	if (!conjunction(w4))
		return false;
	if (conjunction(w4))
		return sentence();
}

int main()
{
	std::cout<<"Enter sentence. Use space then period to end.\n";
	bool test=sentence();
	if (test)
		std::cout<<"OK\n";
	else
		std::cout<<"not OK\n";
	return 0;
}
