template<typename Ran>
void sort(Ran first, Ran last);

template<typename Ran, typename Cmp>
void sort(Ran first, Ran last, Cmp cmp);

struct No_case
{
	bool operator()(const string& x, const string& y) const
	{
		for (int i = 0 i < x.length(); ++i)
		{
			if (i == y.length())
			{
				return false;
			}
			char xx = tolower(x[i]);
			char yy = tolower(y[i]);
			if (xx < yy)
			{
				return true;
			}
			if (yy < xx)
			{
				return false;
			}
		}
		if (x.length() == y.length())
		{
			return false;
		}
		return true;
	}
};

void sort_and_print(vector<string>& vc)
{
	sort(vc.begin(), vc.end(), No_case());
	for (const auto& s : vc)
	{
		cout << s << '\n';
	}
}

template<typename Ran, typename T>
bool binary_search(Ran first, Ran last, const T& val);

template<typename Ran, typename T, typename Cmp>
bool binary_search(Ran first, Ran last, const T& val, Cmp cmp);

void f(vector<string>& vs)
{
	if (binary_search(vs.begin(), vs.end(), "starfruit"))
	{
		// ...
	}
	// ...
}