template<typename T>
class vector
{
public:
	using size_type = unsigned long;
	using value_type = T;
	using iterator = T*;
	using const_iterator = const T*;
	
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	
	size_type size();
};

vector<int>::iterator p = find(v.begin(), v.end(), 32);

for (vector<int>::size_type i = 0; i < v.size(); ++i)
{
	cout << v[i] << '\n';
}