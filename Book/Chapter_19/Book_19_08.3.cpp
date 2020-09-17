vector<int>* make_vec()
{
	unique_ptr<vector<int>> p{new vector<int>};
	// ...
	return p.release();
}