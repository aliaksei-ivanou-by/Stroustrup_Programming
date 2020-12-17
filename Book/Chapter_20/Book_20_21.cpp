void print(Document& d)
{
	for (auto p : d)
	{
		cout << *p;
	}
}

print(my_doc);