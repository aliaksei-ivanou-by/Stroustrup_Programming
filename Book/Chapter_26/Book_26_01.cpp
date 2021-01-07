template<class ForwardIterator, class T>
bool binary_search(
		ForwardIterator first,
		ForwardIterator last,
		const T& value);

template<class ForwardIterator, class T, class Compare>
bool binary_search(
		ForwardIterator first,
		ForwardIterator last,
		const T& value,
		Compare comp);
		
vector<int> v{ 1, 2, 3, 5, 8, 13, 21 };
if(binary_search(v.begin(), v.end(), 1) == false)
{
	cout << "No";
}
if(binary_search(v.begin(), v.end(), 5) == false)
{
	cout << "No";
}
if(binary_search(v.begin(), v.end(), 8) == false)
{
	cout << "No";
}
if(binary_search(v.begin(), v.end(), 21) == false)
{
	cout << "No";
}
if(binary_search(v.begin(), v.end(), -7) == true)
{
	cout << "No";
}
if(binary_search(v.begin(), v.end(), 4) == true)
{
	cout << "No";
}
if(binary_search(v.begin(), v.end(), 22) == true)
{
	cout << "No";
}

vector<int> v{ 1, 2, 3, 5, 8, 13, 21 };
for (int x : { 1, 5, 8, 21, -7, 2, 44 })
{
	if (binary_search(v.begin(), v.end(), x) == false)
	{
		cout << x << ": no\n";
	}
}