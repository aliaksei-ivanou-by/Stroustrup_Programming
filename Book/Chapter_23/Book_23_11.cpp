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
	
	int boys = 0;
	int girls = 0;
	
	while (getline(in, line))
	{
		++lineno;
		smatch matches;
		if (!regex_match(line, matches, row))
		{
			cerr << "Wrong line :" << lineno << '\n';
		}
		if (in.eof())
		{
			cout << "End of file\n";
		}
		
		int curr_boy = from_string<int>(matches[2]);
		int curr_girl = from_string<int>(matches[3]);
		int curr_total = from_string<int>(matches[4]);
		if (curr_boy + curr_girl != curr_total)
		{
			error("Wrong sum in line\n");
		}
		if (matches[1] == "Alle klasser")
		{
			if (curr_boy != boys)
			{
				error("Number of boys is wrong\n");
			}
			if (curr_girl != girls)
			{
				error("Number of girls is wrong\n");
			}
			if (!(in >> ws).eof())
			{
				error("Symbols after last line\n");
			}
			return 0;
		}
		boys += curr_boy;
		girls += curr_girl;
	}
	error("No total line\n");
}