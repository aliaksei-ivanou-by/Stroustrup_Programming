int main()
{
	ifstream in { "table.txt" };
	if (!in)
	{
		error("No file\n");
	}
	string line;
	int lineno = 0;
	
	regex header { R"(^[\w ]+(   [\w ]+)*$)" };
	regex row { R"(^[\w ]+(      \d+)(   \d+)(   \d+)$)" };
	
	if (getline(in, line)
	{
		smatch matches;
		if (!regex_match(line, matches, header)
		{
			error("No header");
		}
		
		while (getline(in, line))
		{
			++lineno;
			smatch matches;
			if (!regex_match(line, matches, row)
			{
				error("Wrong line ", to_string(lineno));
			}
		}
	}
}