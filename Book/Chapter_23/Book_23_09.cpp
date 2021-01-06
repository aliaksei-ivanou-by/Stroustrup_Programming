#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	regex pattern;
	string pat;
	cout << "Enter pattern: ";
	getline(cin, pat);
	try
	{
		pattern = pat;
		cout << "pattern: " << pat << '\n';
	}
	catch (bad_exception)
	{
		cout << "Wrong pattern " << pat << '\n';
		exit(1);
	}
	cout << "Enter strings:\n";
	int lineno = 0;
	for (string line; getline(cin, line); )
	{
		++lineno;
		smatch matches;
		if (regex_search(line, matches, pattern))
		{
			cout << "String: " << lineno << ": " << line << '\n';
			for (int i = 0; i < matches.size(); ++i)
			{
				cout << "\tmatches[" << i << "]: " << matches[i] << '\'n';
			}
		}
		else
		{
			cout << "No match\n";
		}
	}
}