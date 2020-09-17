vector<int>* make_vec()
{
	vector<int>* p = new vector<int>;
	try
	{
		// ...
		return p;
	}
	catch(...)
	{
		delete p;
		throw;
	}
}