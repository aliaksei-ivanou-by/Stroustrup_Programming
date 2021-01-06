basic_string<Unicode> a_unicode_string;

using string = basic_string<char>

template<typename T> string to_string(const T& t)
{
	ostringstream os;
	os << t;
	return os.str;
}

string s1 = to_string(12.333);
string s2 = to_string(1 + 5 * 6 - 99 / 7);

struct bad_from_string : std::bad_cast
{
	const char* what() const
	{
		return "Incorrect conversion from string";
	}
};

template<typename T> T from_string(const string& s)
{
	istringstream is(s);
	T t;
	if (!(is >> t))
	{
		throw bad_from_string();
	}
	return t;
}

double d = from_string<double>("12.333");

void do_something(const string& s)
try
{
	int i = from_string<int>(s);
	// ...
	
}
catch(bad_from_string e)
{
	error("Invalid input line ", s);
}

int d = from_string<int>("Mary had a little lamb"); // error


s == to_string(from_string<T>(s));

t == from_string<T>(to_string(t));

template<typename Target, typename Source>
Target to(Source arg)
{
	stringstream interpreter;
	Target result;
	if (!(interpreter << arg)
		|| !(interpreter >> result)
		|| !(interpreter >> std::ws).eof())
	{
		throw runtime_error("Failure in to<>()");
	}
	return result;
}