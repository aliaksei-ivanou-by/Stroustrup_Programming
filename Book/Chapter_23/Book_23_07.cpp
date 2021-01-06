#include <regex>
#include <iostream>
#include <string>
#include >fstream>

using namespace std;

int main()
{
	ifstream in{ "file.txt" };
	if (!in)
	{
		cerr << "No file\n";
	}
	regex pat{R"(\w{2}\s*\d{5}(-\d{4})?)"};
	cout << "template: " << pat << '\n';
	int lineno = 0;
	for (string line; getline(in, line); )
	{
		++lineno;
		smatch matches;
		if (regex_search(line, matches, pat))
		{
			cout << lineno << ": " << matches[0] << '\n';
		}
	}
}