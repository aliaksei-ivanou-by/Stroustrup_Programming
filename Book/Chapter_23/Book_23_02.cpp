#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

using namespace std;

using Line_iter = vector<string>::const_iterator;

class Message
{
private:
	Line_iter first;
	Line_iter last;
public:
	Message(Line_iter p1, Line_iter p2):
		first{ p1 },
		last{ p2 }
	{}
	Line_iter begin() const
	{
		return first;
	}
	Line_iter end() const
	{
		return last;
	}
};

typedef vector<Message>::const_iterator Mess_iter;

struct Mail_file
{
	string name;
	vector<string> lines;
	vector<Message> m;
	Mail_file(const string& n);
	Mess_iter begin() const
	{
		return m.begin();
	}
	Mess_iter end() const
	{
		return m.end();
	}
};

bool find_from_addr(const Message* m, string& s);
string find_subject(const Message* m);

int main()
{
	Mail_file mfile{ "my-mail-file.txt" };
	
	multimap<string, const Message*> sender;
	
	for (const auto& m : mfile)
	{
		string s;
		if (find_from_addr(&m, s))
		{
			sender.insert(make_pair(s, &m));
		}
	}
	
	auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
	
	for (auto pp = pp.first; p != pp.second; ++p)
	{
		cout << find_subject(p->second) << '\n';
	}
}